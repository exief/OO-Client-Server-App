#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <arpa/inet.h>

class Server {
public:
	Server(const int& port = 5000);
	Server(const Server& other);
	~Server();
	
	Server& operator=(const Server& rhs);
	
	bool operator==(const Server& rhs) const;
	bool operator!=(const Server& rhs) const;
	
	void listen();
	void accept();
	void send(const std::string& msg) const;
	void receive();
protected:
private:
	struct sockaddr_in socketAddress_;
	int fd_;
	int readsize_ = 0;
};
#endif
