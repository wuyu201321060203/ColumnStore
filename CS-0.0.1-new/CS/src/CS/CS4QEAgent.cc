#include <common/comm/SocketAddress.h>

#include <string>
#include <sys/sysinfo.h>
#include <cassert>

#include <CS/CS4QEAgent.h>
#include <CS/Initializer.h>

CS4QEAgent::CS4QEAgent(TCPSocket const& socket , SocketAddress const& addr):
    TCPAgent(socket , addr)
{
}

int CS4QEAgent::init()
{
    TCPAgent::init();
    SocketAddress peerAddr;
    if( SUCCESSFUL == getOppAddr(peerAddr) )
    {
        string ip(peerAddr.getIP());
        LOG_TRACE << " A QE connect to CS and its address is: "
            << ip << ":" << peerAddr.getPort();
    }
    return 0;
}

void CS4QEAgent::readBack(InReq& req)
{
    Initializer::getCodec().onMessage(getID() , req);
}
