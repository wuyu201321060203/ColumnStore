#include <common/comm/SocketAddress.h>

#include <string>
#include <sys/sysinfo.h>
#include <cassert>

#include <CS/CS4DSAgent.h>
#include <CS/Initializer.h>

CS4DSAgent::CS4DSAgent(TCPSocket const& socket , SocketAddress const& addr):
    TCPAgent(socket , addr)
{
}

int CS4DSAgent::init()
{
    TCPAgent::init();
    SocketAddress peerAddr;
    if( SUCCESSFUL == getOppAddr(peerAddr) )
    {
        string ip(peerAddr.getIP());
        LOG_TRACE << " A DS connect to CS and its address is: "
            << ip << ":" << peerAddr.getPort();
    }
    return 0;
}

void CS4DSAgent::readBack(InReq& req)
{
    Initializer::getCodec().onMessage(getID() , req);
}
