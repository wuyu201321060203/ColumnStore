#ifndef DISPATCHER_LITE_H
#define DISPATCHER_LITE_H

#include <google/protobuf/message.h>

#include <map>
#include <utility>

#include <muduo/base/Logging.h>

#include <boost/function.hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>

typedef boost::shared_ptr<google::protobuf::Message> MessagePtr;

class ProtobufDispatcher
{
public:

    typedef boost::function<void (uint32_t,
                                  MessagePtr const&
                                  )> ProtobufMessageCallback;

    explicit ProtobufDispatcher(ProtobufMessageCallback const& defaultCb)
        : _defaultCallback(defaultCb)
    {
    }

    void onProtobufMessage(uint32_t agentID,
                           		   MessagePtr const& message) const
    {
        CallbackMap::const_iterator it = _callbacks.find(message->GetDescriptor());
        if (it != _callbacks.end())
        {
            it->second(agentID, message);
        }
        else
        {
            _defaultCallback(agentID, message);
        }
    }

    void registerMessageCallback(google::protobuf::Descriptor const* desc,
                                 		 ProtobufMessageCallback const& callback)
    {
#ifndef DMTEST
        auto ret = _callbacks.insert(CallbackMap::value_type(desc , callback));
        if(ret.second == false)
            LOG_INFO << "failed to register callback";
#else
        _callbacks.insert(std::make_pair(desc , callback));
#endif
    }

private:

    typedef std::map<google::protobuf::Descriptor const*, ProtobufMessageCallback> CallbackMap;
    CallbackMap _callbacks;
    ProtobufMessageCallback _defaultCallback;
};

#endif
