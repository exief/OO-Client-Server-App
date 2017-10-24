#include "server.h"

Server::Server() {
	this->fd_ = socket(AF_INET, SOCK_STREAM, 0);
	
	this->socketAddress_.sin_family = AF_INET;
	this->socketAddress_.sin_addr.s_addr = htonl(INADDR_ANY);
	this->socketAddress_.sin_port = htons(5000);
	
	bind(this->fd_, (struct sockaddr*) &this->socketAddress_, sizeof(this->socketAddress_));
	
	listen(this->fd_, MAX_CONNECTIONS);
}

Server::Server(const int& port) {

}

Server::Server(const std::string& ip, const int& port) {

}

Server::Server(const Server& other) {

}

Server::~Server() {

}
	
Server::Server& operator=(const Server& rhs) {

}
	
Server::bool operator==(const Server& rhs) const {

}

Server::bool operator!=(const Server& rhs) const { 

}
	
void Server::send(const std::string& msg) const {

}

void Server::receive() {

}
