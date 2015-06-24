#include <iostream>

#include <boost/bind.hpp>
#include <boost/lexical_cast.hpp>

#include <muduo/base/Logging.h>

#include <CS/Config.h>
#include <CS/Initializer.h>

using namespace muduo;

muduo::ThreadPool Initializer::_threadPool;
uint32_t Initializer::_selfModuleID = 0;
uint16_t Initializer::_cliPort = 0;
uint16_t Initializer::_csPort = 0;
uint16_t Initializer::_dsPort = 0;
uint16_t Initializer::_qePort = 0;
std::string Initializer::_dcIP;
uint16_t Initializer::_dcPort = 0;
std::string Initializer::_selfIP;
ProtobufCodec Initializer::_codec( boost::bind(&ProtobufDispatcher::
                onProtobufMessage , &_dispatcher , _1, _2) );
ProtobufDispatcher Initializer::_dispatcher(boost::bind(&Initializer::
                onUnknownMessage , _1 , _2));
XMLParse Initializer::_xmlParser;

int Initializer::init(int argc , char** argv)
{
    if(!parseCommandLineDull(argc , argv))
    {
#ifdef CSDEBUG
        LOG_INFO << "fail to parse command line";
#endif
        return RET_FAIL;
    }
    _threadPool.start(DEFAULT_THREADS);
    return RET_SUCCESS;
}

ThreadPool& Initializer::getThreadPool()
{
    return _threadPool;
}

uint32_t Initializer::getSelfModuleID()
{
    return _selfModuleID;
}

uint16_t Initializer::getCliPort()
{
    return _cliPort;
}

uint16_t Initializer::getCSPort()
{
    return _csPort;
}

uint16_t Initializer::getDSPort()
{
    return _dsPort;
}

uint16_t Initializer::getQEPort()
{
    return _qePort;
}

std::string Initializer::getDCIP()
{
    return _dcIP;
}

uint16_t Initializer::getDCPort()
{
    return _dcPort;
}

std::string Initializer::getSelfIP()
{
    return _selfIP;
}

ProtobufCodec& Initializer::getCodec()
{
    return _codec;
}

ProtobufDispatcher& Initializer::getDispatcher()
{
    return _dispatcher;
}

void Initializer::onUnknownMessage(uint32_t agentID , MessagePtr const& msg)
{
    LOG_INFO << "onUnknownMessage:" << msg->GetTypeName();
}

bool Initializer::parseCommandLineDull(int argc , char* argv[])
{
    _xmlParser.parse();
    return true;
}