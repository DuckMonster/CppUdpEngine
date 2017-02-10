#pragma once
#include "udpcontroller.h"
#include "user.h"

#include <map>

class CServer {
public:
	typedef std::map<udp::endpoint, CUser*>::iterator user_iterator;

public:
	CServer( asio::io_service& service, unsigned short port );

	asio::io_service& GetService( ) { return m_Service; }

	CUser* GetUser( const udp::endpoint& endpoint );
	CUser* AddUser( const udp::endpoint& endpoint );

	INetController* GetNetController( bool safe ) { return &m_UdpController; }

private:
	size_t								m_IDCounter;

	asio::io_service&					m_Service;
	std::map<udp::endpoint, CUser*>		m_UserMap;
	CUdpController						m_UdpController;
};