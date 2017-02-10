#include "udpcontroller.h"
#include "server.h"

#include <iostream>
#include <functional>

CUdpController::CUdpController( CServer* server, unsigned short port ) :
	m_Server( server ),
	m_RecvEPBuffer( ),
	m_Socket( server->GetService( ) ) {

	m_Socket.open( udp::v4( ) );
	m_Socket.bind( udp::endpoint( udp::v4( ), port ) );

	DoRecv( );
}

void CUdpController::Send( const CDatagram & dgram, const CUser * user ) {
	// Do stuff here for sending
}

void CUdpController::DoRecv( ) {
	using namespace std::placeholders;

	m_Socket.async_receive_from(
		asio::buffer( m_RecvBuffer, 1024 ), m_RecvEPBuffer,
		std::bind( &CUdpController::OnRecv, this, _1, _2 ) );
}

void CUdpController::OnRecv( asio::error_code errorCode, size_t bytesReceived ) {
	/*std::cout << "Received " << bytesReceived << " from " <<
		m_RecvEPBuffer.address( ).to_string( ) << ":" << m_RecvEPBuffer.port( ) << "\n";*/

	CUser* usr = m_Server->GetUser( m_RecvEPBuffer );

	if (!usr)
		usr = m_Server->AddUser( m_RecvEPBuffer );

	std::stringstream ss;
	ss << "Hello " << usr->GetID( ) << "!";

	DoSend( new CDatagram( ss.str( ).c_str( ), ss.str( ).size( ) ), m_RecvEPBuffer );
	DoRecv( );
}

void CUdpController::DoSend( CDatagram* datagram, udp::endpoint target ) {
	using namespace std::placeholders;

	m_Socket.async_send_to( asio::buffer( datagram->m_Ptr, datagram->m_Size ),
		target,
		std::bind( &CUdpController::OnSend, this, datagram, _1, _2 ) );
}

void CUdpController::OnSend( CDatagram* datagram, asio::error_code errorCode, size_t bytesSent ) {
	//delete datagram;
	//std::cout << "Sent " << bytesSent << "\n";
}