#include <common/comm/SocketAddress.h>
#include <common/comm/TCPAgent.h>

#include <string>
#include <sys/sysinfo.h>
#include <cassert>

#include <CS/CS4DCAgent.h>
#include <CS/Initializer.h>
#include <CS/Config.h>

CS4DCAgent::CS4DCAgent(SocketAddress const& addr):TCPAgent(addr)
{
}

int CS4DCAgent::init()
{
	if(this->connect() != SUCCESSFUL)
	{
		LOG_INFO << "in CS4DCAgent::init connect DC error";
		return FAILED;
	}
	return SUCCESSFUL;
}

void CS4DCAgent::readBack(InReq& req)
{
    Initializer::getCodec().onMessage(getID() , req);
}

int CS4DCAgent::connectAfter(bool bConnect)
{
    if(bConnect)
    {
        MemInfoSendMsg registerReply;
        struct sysinfo tmp;
        sysinfo(&tmp);
        unsigned long memSize = tmp.freeram/1024/1024;
#ifndef SPEEDTEST
        LOG_INFO << "register mem: " << memSize;//TODO
#endif
        registerReply.set_memory(memSize);
        registerReply.set_port(Initializer::getDSPort());
        Initializer::getCodec().send(getID() , registerReply);
    }
}
