#ifndef INITIALIZER_H
#define INITIALIZER_H

#include <string>

#include <muduo/base/ThreadPool.h>

#include "XMLParse.h"
#include "ProtobufCodec.h"
#include "ProtobufDispatcher.h"

class Initializer
{
public:

    friend class XMLParse;

    static int init(int , char**);
    static muduo::ThreadPool& getThreadPool();
    static uint32_t getSelfModuleID();
    static uint16_t getCliPort();
    static uint16_t getCSPort();
    static uint16_t getDSPort();
    static uint16_t getQEPort();
    static std::string getDCIP();
    static uint16_t getDCPort();
    static std::string getSelfIP();
    static ProtobufCodec& getCodec();
    static ProtobufDispatcher& getDispatcher();

private:

    static uint32_t _selfModuleID;
    static muduo::ThreadPool _threadPool;
    static uint16_t _cliPort;
    static uint16_t _csPort;
    static uint16_t _dsPort;
    static uint16_t _qePort;
    static std::string _dcIP;
    static uint16_t _dcPort;
    static std::string _selfIP;
    static ProtobufCodec _codec;
    static ProtobufDispatcher _dispatcher;

private:

    static void onUnknownMessage(uint32_t , MessagePtr const&);
    static bool parseCommandLineDull(int  , char**);
    static XMLParse _xmlParser;
};

#endif