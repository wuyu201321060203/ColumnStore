#ifndef CS4DSAGENT_H
#define CS4DSAGENT_H

#include <string>

#include <common/comm/TCPAgent.h>
#include <common/comm/TCPSocket.h>
#include <common/comm/SocketAddress.h>

class CS4DSAgent : public TCPAgent
{
public:

    CS4DSAgent(TCPSocket const& , SocketAddress const&);
    int init();
    void readBack(InReq&);
};

#endif
