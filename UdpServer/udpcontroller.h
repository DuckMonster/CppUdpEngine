#pragma once
#include <asio.hpp>
#include "netcontroller.h"
#include "datagram.h"

using asio::ip::udp;

class CServer;

class CUdpController : public INetController {
public:
	CUdpController( CServer* server, unsigned short port );

	virtual void Send( const CDatagram& dgram, const CUser* user ) override;

private:
	void DoRecv( );
	void OnRecv( asio::error_code errorCode, size_t bytesReceived );
	void DoSend( CDatagram* datagram, udp::endpoint target );
	void OnSend( CDatagram* datagram, asio::error_code errorCode, size_t bytesSent );

	CServer*		m_Server;

	char			m_RecvBuffer[1024];
	udp::endpoint	m_RecvEPBuffer;

	char*			m_SendBuffer = "Hello!";

	udp::socket		m_Socket;
};