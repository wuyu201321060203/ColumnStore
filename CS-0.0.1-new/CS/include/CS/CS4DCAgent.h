#ifndef CS4DCAGENT_H
#define CS4DCAGENT_H

#include <common/comm/TCPAgent.h>
#include <common/comm/SocketAddress.h>

class CS4DCAgent : public TCPAgent
{
public:

    CS4DCAgent(SocketAddress const&);
    int init();
    void readBack(InReq& req);
	int connectAfter(bool);
};

#endif
