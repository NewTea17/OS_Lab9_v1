#include <iostream>
#include "Server.h"

int main() {
	Server server;

	server.displayServices();

	server.run();


	return 0;
}