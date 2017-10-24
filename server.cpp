#include "server.h"

Server::Server(const int& port = 5000) {
	this->fd_ = socket(AF_INET, SOCK_STREAM, 0);
	
	this->socketAddress_.sin_family = AF_INET;
	this->socketAddress_.sin_addr.s_addr = htonl(INADDR_ANY);
	this->socketAddress_.sin_port = htons(port);	
	
	bind(this->fd_, (struct sockaddr*) &this->socketAddress_, sizeof(this->socketAddress_));
}

Server::Server(const Server& other) {
	*this = other;
}

Server::~Server() {
	
}
	
Server::Server& operator=(const Server& rhs) {
	this->fd_ = socket(AF_INET, SOCK_STREAM, 0);
	
	this->socketAddress_.sin_family = AF_INET;
	this->socketAddress_.sin_addr.s_addr = htonl(INADDR_ANY);
	this->socketAddress_.sin_port = htons(rhs.socketAddress_.sin_port);	
	
	bind(this->fd_, (struct sockaddr*) &this->socketAddress_, sizeof(this->socketAddress_));
}
	
Server::bool operator==(const Server& rhs) const {
	if(this->socketAddress_.sin_family != rhs.socketAddress_.sin_family) {
		return false;	
	} else if (this->socketAddress_.sin_addr.s_addr != rhs.socketAddress_.sin_addr.s_addr) {
		return false;
	} else if (this->socketAddress_.sin_port != rhs.socketAddress_.sin_port) {
		return false;
	}
	return true;
}

Server::bool operator!=(const Server& rhs) const { 
	return !(*this == rhs);
}
	
void Server::listen() {
	listen(this->fd_, MAX_CONNECTIONS);
}

void Server::send(const std::string& msg) const {
	try {
		if(send(this->fd_, msg.c_str(), msg.length(), 0) < 0) throw -1;
	} catch (int e) {
		std::cout << "Error Sending Message" << std::endl;
	}
}

void Server::receive() {

}
