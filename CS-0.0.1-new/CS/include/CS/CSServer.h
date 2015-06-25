#ifndef CSSERVER_H
#define CSSERVER_H

#include <boost/shared_ptr.hpp>

#include <common/comm/TCPListenAgent.h>
#include "CS4DSAgent.h"
#include "CS4QEAgent.h"

class CS4DCAgent;
class CS4DCService;
class CS4DSService;
class CS4QEService;

typedef boost::shared_ptr<CS4DCService> CS4DCServicePtr;
typedef boost::shared_ptr<CS4DSService> CS4DSServicePtr;
typedef boost::shared_ptr<CS4QEService> CS4QEServicePtr;

class CSServer
{
public:

    CSServer();
    void start();

    CS4DCAgent* getCS4DCAgent()
    {
        return _connector4DC;
    }

    CS4DSServicePtr getDataStorageService()
    {
        return _service4DS;
    }

private:

    friend class CS4DCService;
    friend class CS4DSService;
    friend class CS4QEService;

    CS4DCServicePtr _service4DC;
    CS4DSServicePtr _service4DS;
    CS4QEServicePtr _service4QE;

    TCPListenAgent<CS4DSAgent>* _acceptor4DS;
    TCPListenAgent<CS4QEAgent>* _acceptor4QE;
    CS4DCAgent* _connector4DC;
};

#endif