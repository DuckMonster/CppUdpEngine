#include "user.h"

CUser::CUser( const size_t id, const udp::endpoint & endpoint ) :
	m_ID( id ), m_Endpoint( endpoint ) {
}