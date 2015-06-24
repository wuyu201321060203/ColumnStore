#ifndef CS4DCSERVICE_H
#define CS4DCSERVICE_H

#include <boost/shared_ptr.hpp>

#include "ProtobufCodec.h"

class CSServer;

class CS4DCService
{
public:

    CS4DCService(CSServer* server);
    void onSysStatQuery(uint32_t agentID,
                        MessagePtr const& msg);

    void onIndexSendAck(uint32_t agentID,
                        MessagePtr const& msg);

private:

    void doSysStatQuery(uint32_t agentID,
                        MessagePtr const& msg);

private:

    CSServer* _server;
};

#endif
