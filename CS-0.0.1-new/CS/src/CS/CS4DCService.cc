#include <string>
#include <sys/sysinfo.h>
#include <cassert>

#include <muduo/base/Mutex.h>

#include <common/comm/AgentManager.h>

#include <boost/lexical_cast.hpp>
#include <boost/bind.hpp>

#include <CS/CS4DCService.h>
#include <CS/IndexOffset.h>
#include <CS/BitCompressedVector.h>
#include <CS/DGroupKey.h>
#include <CS/RWMutex.h>
#include <CS/Initializer.h>
#include <CS/CSServer.h>

#ifdef CSTEST
extern SysStatGetAck g_SysStatAck;
extern IndexSendMsg g_IndexSendMsg;
extern IndexSendMsg g_IndexSendMsg1;
#endif

muduo::MutexLock g_Lock;

CS4DCService::CS4DCService(CSServer* server):_server(server)
{
    Initializer::getDispatcher().registerMessageCallback(
        IndexSendAck::descriptor(),
        boost::bind(&CS4DCService::onIndexSendAck , this , _1 , _2)
        );

    Initializer::getDispatcher().registerMessageCallback(
        SysStatGetMsg::descriptor(),
        boost::bind(&CS4DCService::onSysStatQuery , this , _1 , _2)
        );

    ProtobufCodec::registeMsg(MSG_CS_DC_MEMORY_INFO_SEND_CMD,
        "MSG_CS_DC_MEMORY_INFO_SEND");
    ProtobufCodec::registeMsg(MSG_DC_CS_MEMORY_INFO_SEND_ACK_CMD,
        "MSG_DC_CS_MEMORY_INFO_SEND_ACK");
    ProtobufCodec::registeMsg(MSG_CS_DC_LOCATION_INDEX_SEND_CMD,
        "MSG_CS_DC_LOCATION_INDEX_SEND");
    ProtobufCodec::registeMsg(MSG_DC_CS_LOCATION_INDEX_SEND_ACK_CMD,
        "MSG_DC_CS_LOCATION_INDEX_SEND_ACK");
    ProtobufCodec::registeMsg(MSG_DC_CS_SYSTEM_STATUS_GET_CMD,
        "MSG_DC_CS_SYSTEM_STATUS_GET");
    ProtobufCodec::registeMsg(MSG_CS_DC_SYSTEM_STATUS_GET_ACK_CMD,
        "MSG_CS_DC_SYSTEM_STATUS_GET_ACK");
}

void CS4DCService::onSysStatQuery(uint32_t agentID,
                                  MessagePtr const& msg)
{
    (Initializer::getThreadPool()).run(
        boost::bind(&CS4DCService::doSysStatQuery , this , agentID , msg) );
}

void CS4DCService::doSysStatQuery(uint32_t agentID,
                                  MessagePtr const& msg)
{
    SysStatGetAck reply;
    reply.set_statuscode(SUCCESS);
    SINGLE_NODE_INFO* nodeInfo = reply.mutable_nodesysinfo();
    nodeInfo->set_nodeid( Initializer::getSelfModuleID() );
    nodeInfo->set_nodestatus("OK");
    nodeInfo->set_nodeip( Initializer::getSelfIP() );
    nodeInfo->set_nodeport(Initializer::getCliPort());
    int coreNum = get_nprocs();
#ifndef SPEEDTEST
    LOG_INFO << "core num is: " << coreNum;//TODO
#endif
    nodeInfo->set_core(coreNum);
    struct sysinfo tmp;
    sysinfo(&tmp);
    unsigned long memSize = tmp.freeram/1024/1024;
#ifndef SPEEDTEST
    LOG_INFO << "memsize: " << memSize;//TODO
#endif
    nodeInfo->set_memsize(memSize);//MB for unit
#ifndef CSTEST
	if( AgentManager::getInstance()->find(agentID) )
    	Initializer::getCodec().send(agentID , reply);
#else
    g_SysStatAck = reply;
#endif
}

void CS4DCService::onIndexSendAck(uint32_t agentID,
                                  MessagePtr const& msg)
{
    //TODO
}
