#include <stdlib.h>
#include <signal.h>

#include <common/comm/Epoll.h>
#include <common/comm/TCPListenAgent.h>
#include <common/comm/AgentManager.h>
#include <common/util/util.h>

#include <CS/Initializer.h>
#include <CS/AsyncLogging.h>
#include <CS/CSServer.h>
#include <CS/CS4DCAgent.h>

#include <muduo/base/Logging.h>

AsyncLogging* g_asyncLog = NULL;
Epoll* g_pEpoll = NULL;

int const EPOLLSIZE = 1024;

void doExit(int signo)
{
	if(SIGINT == signo)
	{
		LOG_INFO << "server sigint catch";
		if(NULL != g_pEpoll)
			g_pEpoll->finish();
	}
}

void asyncOutput(char const* msg, int len)
{
    g_asyncLog->append(msg, len);
}

int main(int argc , char** argv)
{
    if( Initializer::init(argc , argv) )
        return 0;
	g_pEpoll = new Epoll();
	if(g_pEpoll->initialize(EPOLLSIZE) == FAILED)
	{
		LOG_ERROR << "In main: init epoll error!";
		delete g_pEpoll;
		g_pEpoll = NULL;
		return FAILED;
	}

    /*
    char name[256];
    strncpy(name, argv[0], 256);
    AsyncLogging log(::basename(name), ROLL_SIZE);
    log.start();
    g_asyncLog = &log;
    muduo::Logger::setOutput(asyncOutput);
    */
    CSServer* CS = new CSServer;
    CS->start();

	if(signal(SIGINT , doExit) == SIG_ERR)
	{
		LOG_ERROR << "In main: set SIGINT(catch \"ctrl + c\") signal error!";
		return FAILED;
	}

	g_pEpoll->run();

	AgentManager::destroyInstance();
	if( g_pEpoll != NULL)
	{
		delete g_pEpoll;
		g_pEpoll = NULL;
	}
    //never get here
}