#include "server.h"

#include <iostream>

CServer::CServer( asio::io_service& service, unsigned short port ) :
	m_Service( service ),
	m_UdpController( this, port ),
	m_IDCounter( 0 ) {

	service.run( );
}

CUser* CServer::GetUser( const udp::endpoint & endpoint ) {
	user_iterator it = m_UserMap.find( endpoint );

	if (it == m_UserMap.end( ))
		return NULL;

	return it->second;
}

CUser* CServer::AddUser( const udp::endpoint & endpoint ) {
	if (GetUser( endpoint ) != NULL)
		throw std::exception( "Tried to add a user that already exists" );

	CUser* user = new CUser( m_IDCounter, endpoint );
	m_UserMap[endpoint] = user;

	std::cout << "User " << user->GetID( ) << " ( "
		<< user->GetEndpoint( ).address( ).to_string( ) << ":" << user->GetEndpoint( ).port( )
		<< " ) connected!\n";

	m_IDCounter++;
	return user;
}
