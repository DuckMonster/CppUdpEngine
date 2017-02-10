#pragma once
#include <asio.hpp>
using asio::ip::udp;

class CUser {
public:
	CUser( const size_t id, const udp::endpoint& endpoint );

	const size_t GetID( ) { return m_ID; }
	const udp::endpoint& GetEndpoint( ) { return m_Endpoint; }

private:
	const size_t			m_ID;
	const udp::endpoint		m_Endpoint;
};