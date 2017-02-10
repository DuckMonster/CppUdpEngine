#pragma once
class CDatagram {
public:
	char*		m_Ptr;
	size_t		m_Size;

	CDatagram( ) = delete;
	CDatagram( CDatagram&& other ) = delete;
	CDatagram( const char* const ptr, const size_t size );
	~CDatagram( );
};