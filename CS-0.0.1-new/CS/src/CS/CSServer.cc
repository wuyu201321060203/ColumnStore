#include <common/comm/AgentManager.h>

#include <CS/CSServer.h>
#include <CS/CS4DCAgent.h>
#include <CS/Initializer.h>
#include <CS/Config.h>

CSServer::CSServer():_service4DC(this),
                     _server4DS(this),
                     _server4QE(this , SHM_PATH),
    _acceptor4DS( (AgentManager::getInstance())->createAgent<TCPListenAgent<CS4DSAgent> >(
        SocketAddress(Initializer::getSelfIP().c_str(),
                      (unsigned short)Initializer::getDSPort())
        ) ),
    _acceptor4QE( (AgentManager::getInstance())->createAgent<TCPListenAgent<CS4QEAgent> >(
        SocketAddress(Initializer::getSelfIP().c_str(),
                      (unsigned short)Initializer::getQEPort())
        ) ),
    _connector4DC( (AgentManager::getInstance())->createAgent<CS4DCAgent>(
        SocketAddress(Initializer::getDCIP().c_str(),
                      (unsigned short)Initializer::getDCPort())
        ) )
{}

void CSServer::start()
{
    _acceptor4DS->init();
    _acceptor4QE->init();
    _connector4DC->init();
}