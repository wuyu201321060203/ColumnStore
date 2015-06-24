#ifndef PROTOBUF_RAS_CODEC_H
#define PROTOBUF_RAS_CODEC_H

#include <map>
#include <string>
#include <cassert>

#include <common/comm/TCPAgent.h>
#include <common/comm/AgentManager.h>

#include <boost/function.hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>

#include <google/protobuf/message.h>

/*
struct ProtobufTransportFormat __attribute__ ((__packed__))
{
    uint32_t  cmd;
    uint32_t  length;
    uint32_t  error;
    uint32_t  para1;
    uint32_t  para2;
    char      protobufData[length + 1];
}
*/

typedef boost::shared_ptr<google::protobuf::Message> MessagePtr;
typedef std::map<uint32_t , std::string> Cmd2TypeNameMap;
typedef std::map<std::string , uint32_t> TypeName2CmdMap;

class ProtobufCodec : boost::noncopyable
{
public:

    enum ErrorCode
    {
        kNoError = 0,
        kInvalidLength,
        kUnknownMessageType,
        kParseError,
    };

    typedef boost::function<void (uint32_t agentID , MessagePtr const&)>
                        ProtobufMessageCallback;

    typedef boost::function<void (uint32_t agentID , ErrorCode)> ErrorCallback;

    explicit ProtobufCodec(ProtobufMessageCallback const& messageCb)
                                        : _messageCallback(messageCb),
                                          _errorCallback(defaultErrorCallback)
    {
    }

    ProtobufCodec(ProtobufMessageCallback const& messageCb , ErrorCallback const& errorCb)
                                        : _messageCallback(messageCb),
                                          _errorCallback(errorCb)
    {
    }

    void onMessage(uint32_t agentID , InReq& req);

    void send(uint32_t agentID , google::protobuf::Message const& message)
    {
        int packageLength = -1;
        char* sendBuf = fillEmptyBuffer(message , packageLength);
        if(AgentManager::getInstance()->find(agentID))
        {
            TCPAgent* tmp = dynamic_cast<TCPAgent*>( AgentManager::getInstance()
                ->get(agentID) );
            assert(packageLength != -1);
            tmp->writeToBuffer( sendBuf ,  packageLength);
        }
    }

    static std::string const& errorCodeToString(ErrorCode errorCode);

    static char* fillEmptyBuffer(google::protobuf::Message const& message,
                                int& length);

    static google::protobuf::Message* createMessage(std::string const& type_name);
    static MessagePtr parse(char const* buf, int len, uint32_t cmd , ErrorCode* errorCode);

    static uint32_t getCmdByTypename(std::string const&);
    static std::string getTypenameByCmd(uint32_t);
    static void registeMsg(uint32_t const& , std::string const&);

private:

    static void defaultErrorCallback(uint32_t agentID,
                                     ErrorCode);

    ProtobufMessageCallback _messageCallback;
    ErrorCallback _errorCallback;

    static int const kHeaderLen = ( sizeof(uint32_t) )*5;
    static int const kMinMessageLen = 0;
    static int const kMaxMessageLen = 1024*1024*1024;

    static Cmd2TypeNameMap _cmd2TypeName;
    static TypeName2CmdMap _typeName2Cmd;
};

#endif
