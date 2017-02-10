#include "heartbeat.h"
#include "server.h"

namespace {

}

CHeartbeatController::CHeartbeatController( INetController* controller ) :
	m_Controller( controller ),
	m_Thread( ) {
}

CHeartbeatController::~CHeartbeatController( ) {

	m_Thread.join( );
}

void CHeartbeatController::SendHeartbeat( const std::vector<CUser*>& users ) {
	for (CUser* usr : users) {
		m_Controller->Send(  )
	}
}
