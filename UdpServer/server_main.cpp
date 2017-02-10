#include <iostream>
#include "server.h"

int main( ) {
	asio::io_service service;
	CServer server( service, 1520 );
}