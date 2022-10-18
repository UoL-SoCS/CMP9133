// Adapted from http://www.linuxhowtos.org/C_C++/socket.htm

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <thread>

using namespace std;

class Client {
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];

    public:
	void msg(const char*);
	void start(const char*, const char*);
	void sendmsg();
	void getmsg();
	void interact();
};

void Client::msg(const char* text) {
    close(sockfd);
    perror(text);
    exit(0);
}

void Client::start(const char* ipaddress, const char* port) {
    int portnum = atoi(port);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        msg("ERROR opening socket");

    server = gethostbyname(ipaddress);
    if (server == NULL) {
	msg("ERROR no such host");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portnum);
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        msg("ERROR connecting");
    else
	cout << "Connected!" << endl;
    
    /*char data;
    if (recv(sockfd, &buffer, 1, MSG_PEEK | MSG_DONTWAIT) < 0) {
        msg("ERROR couldn't connect");
    }*/
}

void Client::sendmsg() {
    while (true) {
	printf("Client: ");
	bzero(buffer, 256);
	fgets(buffer, 255, stdin);
	int n = write(sockfd, buffer, strlen(buffer)-1);
	if (n < 0) 
	    msg("ERROR writing to socket");
    }
}

void Client::getmsg() {
    while (true) {
	bzero(buffer, 256);
	int n = read(sockfd, buffer, 255);
	if (n < 0) 
	    msg("ERROR reading from socket");
	else if (n == 0)
	    break;

	printf("MsgFromServer> %s %d\n",buffer, n); 
    }
}

void Client::interact() {
    std::thread t(&Client::getmsg, this);
    sendmsg();
    t.join();
}

int main(int argc, const char* argv[]) {
    if (argc < 3) {
	cout << "Usage: " << argv[0] << " hostname port" << endl;
    } else {
	Client client;
	client.start(argv[1], argv[2]);
	client.interact();
    }

    return 0;
}
