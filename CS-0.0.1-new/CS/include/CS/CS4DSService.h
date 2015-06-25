#ifndef CS4DSSERVICE_H
#define CS4DSSERVICE_H

#include <string>

#include <boost/shared_ptr.hpp>
#include <boost/unordered_map.hpp>

#include <muduo/base/Mutex.h>

#include "TableManager.h"
#include "DRowTable.h"
#include "ProtobufCodec.h"

typedef boost::shared_ptr<TableManager> TableManagerPtr;
typedef boost::shared_ptr<DRowTable> DRowTablePtr;

class CSServer;
class CS4QEService;

class CS4DSService
{
public:

    CS4DSService(CSServer* server);

private:

    friend class CS4QEService;

    boost::unordered_map<DB_ID_TYPE , TableManagerPtr> _dbID2TManager;
    boost::unordered_map<std::string , DRowTablePtr> _dbID2RTable;
    muduo::MutexLock _tbCreateMutex;
    muduo::MutexLock _rtableCreateMutex;

public:

    void onCreateGroupKeyData(uint32_t agentID,
                              		   MessagePtr const& msg);

    void onUpdateGroupKeyData(uint32_t agentID,
                              		    MessagePtr const& msg);

    void onRTableCreate(uint32_t agentID,
                        	  MessagePtr const& msg);

    void onRTableUpdate(uint32_t agentID,
                        	   MessagePtr const& msg);

private:

    void doCreateGroupKeyData(uint32_t agentID,
                              		   MessagePtr const& msg);

    void doUpdateGroupKeyData(uint32_t agentID,
                              		    MessagePtr const& msg);

    void doRTableCreate(uint32_t agentID,
                        	  MessagePtr const& msg);

    void doRTableUpdate(uint32_t agentID,
                        	   MessagePtr const& msg);

private:

    CSServer* _server;
};

#endif
