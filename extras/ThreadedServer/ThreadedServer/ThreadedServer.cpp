#undef UNICODE

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <thread>
#include <sstream>
#include <mutex>
#include <ThreadPool.h>

#pragma comment (lib, "Ws2_32.lib")

#define DEFAULT_BUFLEN 512
#define MAX_NUM_CLIENTS 2

namespace info {
	std::mutex mtx;
	SOCKET ListenSocket[MAX_NUM_CLIENTS];
	SOCKET ClientSocket[MAX_NUM_CLIENTS];
}

class Server {
	WSADATA wsaData;
	int iResult;

	struct addrinfo *result = NULL;
	struct addrinfo hints;

	int iSendResult;
	char recvbuf[DEFAULT_BUFLEN];
	int recvbuflen = DEFAULT_BUFLEN;

	int portnum;
	int clientid;

public:
	Server(int, int);
	void connect();
	void interact();
	void terminate();
};

Server::Server(int port, int i) {
	this->portnum = port + i;
	this->clientid = i;
}

void Server::connect() {
	info::ListenSocket[clientid] = INVALID_SOCKET;
	info::ClientSocket[clientid] = INVALID_SOCKET;

	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed with error: %d\n", iResult);
		return;
	}
	
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	// Resolve the server address and port
	std::string s = std::to_string(portnum);
	const char* portstr = s.c_str();
	iResult = getaddrinfo(NULL, portstr, &hints, &result);
	//iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
	if (iResult != 0) {
		printf("getaddrinfo failed with error: %d\n", iResult);
		WSACleanup();
		return;
	}

	// Create a SOCKET for connecting to server
	info::ListenSocket[clientid] = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (info::ListenSocket[clientid] == INVALID_SOCKET) {
		printf("socket failed with error: %ld\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		return;
	}

	// Setup the TCP listening socket
	iResult = bind(info::ListenSocket[clientid], result->ai_addr, (int)result->ai_addrlen);
	if (iResult == SOCKET_ERROR) {
		printf("bind failed with error: %d\n", WSAGetLastError());
		freeaddrinfo(result);
		closesocket(info::ListenSocket[clientid]);
		WSACleanup();
		return;
	}

	freeaddrinfo(result);

	iResult = listen(info::ListenSocket[clientid], SOMAXCONN);
	if (iResult == SOCKET_ERROR) {
		printf("listen failed with error: %d\n", WSAGetLastError());
		closesocket(info::ListenSocket[clientid]);
		WSACleanup();
		return;
	}

	// Accept a client socket
	info::ClientSocket[clientid] = accept(info::ListenSocket[clientid], NULL, NULL);
	if (info::ClientSocket[clientid] == INVALID_SOCKET) {
		printf("accept failed with error: %d\n", WSAGetLastError());
		closesocket(info::ListenSocket[clientid]);
		WSACleanup();
		return;
	}
}

void Server::interact() {
	while (true) {
		printf("listening\n");
		iResult = recv(info::ClientSocket[clientid], recvbuf, recvbuflen, 0);
		if (iResult > 0) {
			printf("Client %d says: %s\n", portnum, recvbuf);

			info::mtx.lock();
			/*std::string reply = "Did you say '";
			reply += recvbuf;
			reply += "'?";*/
			printf("broadcasting\n");
			for (int i = 0; i < MAX_NUM_CLIENTS; i++) {
				if (clientid == i) continue;
				//iSendResult = send(info::ClientSocket[i], reply.c_str(), iResult, 0);
				iSendResult = send(info::ClientSocket[i], recvbuf, iResult, 0);
				if (iSendResult == SOCKET_ERROR) {
					printf("send failed with error: %d\n", WSAGetLastError());
					terminate();
					return;
				}
			}
			info::mtx.unlock();
		}
		else if (iResult == 0)
			printf("Connection closing...\n");
		else {
			printf("recv failed with error: %d\n", WSAGetLastError());
			terminate();
			return;
		}
	}
}

void Server::terminate() {
	// shutdown the connection since we're done
	iResult = shutdown(info::ClientSocket[clientid], SD_SEND);
	if (iResult == SOCKET_ERROR) {
		printf("shutdown failed with error: %d\n", WSAGetLastError());
		closesocket(info::ClientSocket[clientid]);
		WSACleanup();
		return;
	}

	// cleanup
	closesocket(info::ClientSocket[clientid]);
	WSACleanup();
}

int main(int argc, const char* argv[]) {
	if (argc < 2) {
		printf("Usage: %s port\n", argv[0]); 

	} else {
		std::vector<Server> servers;
		ThreadPool threads(MAX_NUM_CLIENTS);
		for (int i = 0; i<MAX_NUM_CLIENTS; i++) {
			int port = atoi(argv[1]);
			threads.enqueue([port, i] {
				printf("Starting client %d\n", (port + i));
				Server server = Server(port, i);
				server.connect();
				server.interact();
			});
		}

		printf("LAUNCHED...\n");
	}

	return 0;
}
