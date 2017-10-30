//Language Defined Libraries
#include <iostream>
#include <cstdlib>

//User Defined Libraries
#include "server.h"

int main(int argc, char** argv){
	try {
		Server* svr = new Server();
		svr->listen();
		svr->accept();
		svr->~Server();
	} catch(...) {
		std::cerr << "Error Creating Server Object" << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
