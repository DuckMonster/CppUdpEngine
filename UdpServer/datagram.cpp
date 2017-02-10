#include "datagram.h"
#include <memory.h>

CDatagram::CDatagram( const char * const ptr, const size_t size ) :
	m_Ptr( NULL ), m_Size( size ) {

	m_Ptr = new char[size];
	memcpy( m_Ptr, ptr, size );
}

CDatagram::~CDatagram( ) {
	delete[] m_Ptr;

	m_Ptr = NULL;
	m_Size = 0;
}
