#ifndef CSSERVER_H
#define CSSERVER_H

#include <common/comm/TCPListenAgent.h>
#include "CS4DSAgent.h"
#include "CS4QEAgent.h"
#include "CS4DCService.h"
#include "CS4DSService.h"
#include "CS4QEService.h"

class CS4DCAgent;

class CSServer
{
public:

    CSServer();
    void start();

    CS4DCAgent* getCS4DCAgent()
    {
        return _connector4DC;
    }

    CS4DSService* getDataStorageService()
    {
        return &_service4QE;
    }

private:

    friend class CS4DCService;
    friend class CS4DSService;
    friend class CS4QEService;

    CS4DCService _service4DC;
    CS4DSService _service4DS;
    CS4QEService _service4QE;

    TCPListenAgent<CS4DSAgent>* _acceptor4DS;
    TCPListenAgent<CS4QEAgent>* _acceptor4QE;
    CS4DCAgent* _connector4DC;
};

#endif