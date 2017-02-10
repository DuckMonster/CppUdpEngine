#include <iostream>
#include <asio.hpp>
#include <thread>
using namespace std;
using asio::ip::udp;

int main( ) {
	asio::io_service service;
	udp::socket socket( service );
	socket.open( udp::v4( ) );

	udp::endpoint targetEndpoint;

	udp::resolver resolver( service );
	targetEndpoint = *resolver.resolve( { udp::v4(), "localhost", "1520" } );

	while (true) {
		cout << "Sending... ";

		char msg[512];

		socket.send_to( asio::buffer( "Hello!", 6 ), targetEndpoint );
		size_t recv = socket.receive_from( asio::buffer( msg, 512 ), targetEndpoint );

		msg[recv] = '\0';

		cout << "Received '" << msg << "'\n";

		std::this_thread::sleep_for( std::chrono::milliseconds( 50 ) );
	}

	cout << "Closing down...!\n";
	system( "pause" );
}