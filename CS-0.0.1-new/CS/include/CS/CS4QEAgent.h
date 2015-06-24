#ifndef CS4QEAGENT_H
#define CS4QEAGENT_H

#include <string>

#include <common/comm/TCPAgent.h>
#include <common/comm/TCPSocket.h>
#include <common/comm/SocketAddress.h>

class CS4QEAgent : public TCPAgent
{
public:

    CS4QEAgent(TCPSocket const& , SocketAddress const&);
    int init();
    void readBack(InReq&);
};

#endif
