#pragma once
#include <thread>
#include <vector>
#include "netcontroller.h"
#include "user.h"

class CServer;

class CHeartbeatController {
public:
	CHeartbeatController( INetController* controller );
	~CHeartbeatController( );

private:
	void SendHeartbeat( const std::vector<CUser*>& users );

	INetController*	m_Controller;
	std::thread		m_Thread;

};