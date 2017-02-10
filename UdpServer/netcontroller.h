#pragma once
#include "user.h"
#include "datagram.h"

class INetController {
public:
	virtual void Send( const CDatagram& dgram, const CUser* user ) = 0;

private:

};