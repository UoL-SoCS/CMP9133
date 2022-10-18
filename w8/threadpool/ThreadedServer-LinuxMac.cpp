#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <mutex>
#include <ThreadPool.h>

#define MAX_NUM_CLIENTS 2

using namespace std;

namespace info {
    std::mutex mtx;
    int sockfd[MAX_NUM_CLIENTS];
    int newsockfd[MAX_NUM_CLIENTS];
}

class Server {
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char buffer[256];
    int portnum;
    int clientid;

    public:
	Server(int, int);
	void msg(const char*);
	void connect();
	void interact();
	void broadcast();
};

Server::Server(int port, int i) {
	this->portnum = port+i;
	this->clientid = i;
}

void Server::msg(const char* text) {
    close(info::newsockfd[clientid]);
    close(info::sockfd[clientid]);
    perror(text);
    exit(0);
}

void Server::connect() {
     info::sockfd[clientid] = socket(AF_INET, SOCK_STREAM, 0);
     if (info::sockfd[clientid] < 0) 
        msg("ERROR opening socket");

     bzero((char *) &serv_addr, sizeof(serv_addr));
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portnum);
    if (::bind(info::sockfd[clientid], (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
	msg("ERROR on binding");

     listen(info::sockfd[clientid],5);
     socklen_t clilen = sizeof(cli_addr);
     info::newsockfd[clientid] = accept(info::sockfd[clientid], (struct sockaddr *) &cli_addr, &clilen);
     if (info::newsockfd[clientid] < 0) 
	msg("ERROR on accept");
    else
	cout << "Client " << portnum << " accepted!" << endl;
    write(info::newsockfd[clientid], "CMP9133M", 64);
}

void Server::interact() {
    while (true) {
    	cout << "listening" << endl;
	bzero(buffer,256);
	int n = read(info::newsockfd[clientid], buffer, 255);
	if (n < 0) msg("ERROR reading from socket");
	cout << "Client " << portnum << " says: " << buffer << endl;

	info::mtx.lock();
	string reply = "Client ";
	reply += std::to_string(portnum);
	reply += " says '";
	reply += buffer;
	reply += "'";
	cout << "broadcasting" << endl;
	for (int i=0; i<MAX_NUM_CLIENTS; i++) {
		n = write(info::newsockfd[i], reply.c_str(), 64);
		if (n < 0) msg("ERROR writing to socket");
	}
	info::mtx.unlock();
    }
}

int main(int argc, const char* argv[]) {
    if (argc < 2) {
	cout << "Usage: " << argv[0] << " port" << endl;

    } else {
	std::vector<Server> servers;
    	ThreadPool threads(MAX_NUM_CLIENTS);
	for (int i=0; i<MAX_NUM_CLIENTS; i++) {
		int port = atoi(argv[1]);
		threads.enqueue([port, i] {
			cout << "Starting client " << (port+i) << endl;
			Server server = Server(port, i);
 			server.connect();
			server.interact();
		});
	}

	cout << "LAUNCHED..." << endl;
    }

    return 0;
}
