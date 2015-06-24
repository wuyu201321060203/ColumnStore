#include <string>
#include <string.h>
#include <endian.h>

#include <common/comm/TCPAgent.h>
#include <common/comm/Error.h>
#include <common/comm/BufferManager.h>
#include <common/comm/AgentManager.h>

#include <google/protobuf/descriptor.h>
#include <muduo/net/protorpc/google-inl.h>
#include <muduo/base/Logging.h>

#include <CS/ProtobufCodec.h>
#include <CS/Config.h>

Cmd2TypeNameMap ProtobufCodec::_cmd2TypeName;
TypeName2CmdMap ProtobufCodec::_typeName2Cmd;

using std::string;

char* ProtobufCodec::fillEmptyBuffer(google::protobuf::Message const& message,
                                     int& packageLength)
{
    MsgHeader header;
    std::string const& typeName = message.GetTypeName();
    header.cmd = getCmdByTypename(typeName);
    GOOGLE_DCHECK(message.IsInitialized()) <<
        InitializationErrorMessage("serialize", message);
    int byte_size = message.ByteSize();
    header.length = byte_size;
    header.error = -1;
    header.para1 = -1;
    header.para2 = -1;
    uint32_t msgLength = byte_size + sizeof(MsgHeader);
    char* buf = new char[msgLength + 1];
    memset(buf , 0 , msgLength + 1);
    memcpy(buf , &header , sizeof(MsgHeader));
    uint8_t* start = reinterpret_cast<uint8_t*>(buf + sizeof(MsgHeader));
    uint8_t* end = message.SerializeWithCachedSizesToArray(start);
    if (end - start != byte_size)
    {
        ByteSizeConsistencyError(byte_size, message.ByteSize(),
            static_cast<int>(end - start));
    }
    packageLength = msgLength;
    return buf;
}

namespace
{
    string const kNoErrorStr = "NoError";
    string const kInvalidLengthStr = "InvalidLength";
    string const kUnknownMessageTypeStr = "UnknownMessageType";
    string const kParseErrorStr = "ParseError";
    string const kUnknownErrorStr = "UnknownError";
}

string const& ProtobufCodec::errorCodeToString(ErrorCode errorCode)
{
    switch (errorCode)
    {
    case kNoError:
        return kNoErrorStr;
    case kInvalidLength:
        return kInvalidLengthStr;
    case kUnknownMessageType:
        return kUnknownMessageTypeStr;
    case kParseError:
        return kParseErrorStr;
    default:
        return kUnknownErrorStr;
    }
}

void ProtobufCodec::defaultErrorCallback(uint32_t agentID , ErrorCode errorCode)
{
    LOG_ERROR << "ProtobufCodec::defaultErrorCallback - " <<
                                                        errorCodeToString(errorCode);
    if( AgentManager::getInstance()->find(agentID) )//TODO
        AgentManager::getInstance()->recycle(agentID);
}

void ProtobufCodec::onMessage(uint32_t agentID , InReq& req)
{
    uint32_t cmd = req.m_msgHeader.cmd;
    uint32_t length = req.m_msgHeader.length;
    if(length > kMaxMessageLen)
        _errorCallback(agentID , kInvalidLength);
    else
    {
        ErrorCode errorCode = kNoError;
        MessagePtr message = parse(req.ioBuf, length , cmd , &errorCode);
        if(errorCode == kNoError && message)
            _messageCallback(agentID , message);
        else
            _errorCallback(agentID , errorCode);
    }
}

google::protobuf::Message* ProtobufCodec::createMessage(std::string const& typeName)
{
    google::protobuf::Message* message = NULL;
    google::protobuf::Descriptor const* descriptor =
        google::protobuf::DescriptorPool::generated_pool()->FindMessageTypeByName(typeName);
    if(descriptor)
    {
        google::protobuf::Message const* prototype =
            google::protobuf::MessageFactory::generated_factory()->GetPrototype(descriptor);
        if(prototype)
        {
            message = prototype->New();
        }
    }
    return message;
}

MessagePtr ProtobufCodec::parse(char const* buf , int len , uint32_t cmd,
                                   ErrorCode* error)
{
    MessagePtr message;
    std::string typeName = getTypenameByCmd(cmd);
    message.reset(createMessage(typeName));
    if(message)
    {
        if(message->ParseFromArray(buf, len))
            *error = kNoError;
        else
            *error = kParseError;
    }
    else
        *error = kUnknownMessageType;
    return message;
}

uint32_t ProtobufCodec::getCmdByTypename(STDSTR const& typeName)
{
    return _typeName2Cmd[typeName];
}

STDSTR ProtobufCodec::getTypenameByCmd(uint32_t cmd)
{
    return _cmd2TypeName[cmd];
}

void ProtobufCodec::registeMsg(uint32_t const& cmd , STDSTR const& typeName)
{
    _cmd2TypeName.insert(Cmd2TypeNameMap::value_type(cmd , typeName));
    _typeName2Cmd.insert(TypeName2CmdMap::value_type(typeName , cmd));
}
