all: server-main.o server.o
	g++ -o server server-main.o server.o
server-main.o: server-main.cpp server.o
	g++ -c server-main server.o
server.o: server.cpp
	g++ -c server.cpp
