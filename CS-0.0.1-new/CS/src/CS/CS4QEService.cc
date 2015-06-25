#include <cstring>

#include <boost/bind.hpp>

#include <muduo/net/Callbacks.h>

#include <common/comm/AgentManager.h>

#include <CS/CS4QEService.h>
#include <CS/Initializer.h>
#include <CS/ProtobufCodec.h>
#include <CS/Util.h>

using std::string;

CS4QEService::CS4QEService(CSServer* server , std::string filePath):
    _csserver(server),
    _groupKeyQE(new GroupKeyQueryEngineProxy),
    _shMemManager( new ShMemManager(filePath) )
{
    Initializer::getDispatcher().registerMessageCallback(
        ReqColByFilterMsg::descriptor(),
        boost::bind(&CS4QEService::onQEQuery4ValueByFilter , this , _1 , _2)
        );

    Initializer::getDispatcher().registerMessageCallback(
        ReqColByDictIndexMsg::descriptor(),
        boost::bind(&CS4QEService::onQEQuery4ValueByIndex , this , _1 , _2)
        );

    Initializer::getDispatcher().registerMessageCallback(
        ReqDictIndexMsg::descriptor(),
        boost::bind(&CS4QEService::onQEQuery4IndexByRowkey , this , _1 , _2)
        );

    ProtobufCodec::registeMsg(MSG_QE_CS_REQUEST_COLUMN_CMD,
        "MSG_QE_CS_REQUEST_COLUMN");

    ProtobufCodec::registeMsg(MSG_CS_QE_REQUEST_COLUMN_ACK_CMD,
        "MSG_CS_QE_REQUEST_COLUMN_ACK");

    ProtobufCodec::registeMsg(MSG_QE_CS_DICTINDEX_VALUE_CMD,
        "MSG_QE_CS_DICTINDEX_VALUE");

    ProtobufCodec::registeMsg(MSG_CS_QE_DICTINDEX_VALUE_ACK_CMD,
        "MSG_CS_QE_DICTINDEX_VALUE_ACK");
    ProtobufCodec::registeMsg(MSG_QE_CS_ROWKEY_DICTINDEX_CMD,
        "MSG_QE_CS_ROWKEY_DICTINDEX");
    ProtobufCodec::registeMsg(MSG_CS_QE_ROWKEY_DICTINDEX_ACK_CMD,
        "MSG_CS_QE_ROWKEY_DICTINDEX_ACK");
}

void CS4QEService::onQEQuery4ValueByFilter(uint32_t agentID , MessagePtr const& queryMsg)
{
    ReqColByFilterMsgPtr query = muduo::down_pointer_cast<ReqColByFilterMsg>(queryMsg);
    ReqColByFilterAck reply;
    ColObjType colObj;
    if( RET_SUCCESS == parseCommonInfoOfQuery(query , reply , colObj) )
    {
        bool returnDataType = query->return_data_type();
        bool isLocal = query->is_local();
        size_t colDataType = colObj.second;
        reply.set_status_code(SUCCESS);
        uint32_t cmd;
        string rowKey;
        string freq;
        string value;
        //string
        if(colDataType == GROUPKEY_STRING)
        {
            DGroupKey<string>* groupKey = static_cast<DGroupKey<string>*>(colObj.first);
            string base;
            reply.set_value_type(GROUPKEY_STRING);
            if(returnDataType)
            {
                for(UINT i = 0 ; i != query->filter_size() ; ++i)
                {
                    cmd = ( query->filter(i) ).operator_();
                    base = ( query->filter(i) ).str_data();
                    _groupKeyQE->executeQuery(cmd , base , *groupKey , rowKey,
                                              freq , value);
                }
            }
            else
            {
                for(UINT i = 0 ; i != query->filter_size() ; ++i)
                {
                    cmd = ( query->filter(i) ).operator_();
                    base = ( query->filter(i) ).str_data();
                    _groupKeyQE->executeQuery(cmd , base , *groupKey , rowKey);
                }
            }
        }
        //int
        else if(colDataType == GROUPKEY_INT)
        {
            DGroupKey<int>* groupKey = static_cast<DGroupKey<int>*>(colObj.first);
            int base;
            reply.set_value_type(GROUPKEY_INT);
            if(returnDataType)
            {
                for(UINT i = 0 ; i != query->filter_size() ; ++i)
                {
                    cmd = ( query->filter(i) ).operator_();
                    base = ( query->filter(i) ).int_data();
                    _groupKeyQE->executeQuery(cmd , base , *groupKey , rowKey,
                                              freq , value);
                }
            }
            else
            {
                for(UINT i = 0 ; i != query->filter_size() ; ++i)
                {
                    cmd = ( query->filter(i) ).operator_();
                    base = ( query->filter(i) ).int_data();
                    _groupKeyQE->executeQuery(cmd , base , *groupKey , rowKey);
                }
            }
        }
        //double
        else
        {
            DGroupKey<double>* groupKey = static_cast<DGroupKey<double>*>(colObj.first);
            double base;
            reply.set_value_type(GROUPKEY_DOUBLE);
            if(returnDataType)
            {
                for(UINT i = 0 ; i != query->filter_size() ; ++i)
                {
                    cmd = ( query->filter(i) ).operator_();
                    base = ( query->filter(i) ).double_data();
                    _groupKeyQE->executeQuery(cmd , base , *groupKey , rowKey,
                                              freq , value);
                }
            }
            else
            {
                for(UINT i = 0 ; i != query->filter_size() ; ++i)
                {
                    cmd = ( query->filter(i) ).operator_();
                    base = ( query->filter(i) ).double_data();
                    _groupKeyQE->executeQuery(cmd , base , *groupKey , rowKey);
                }
            }
        }

        if(isLocal)
        {
            UINT length;
            int ret;
            if(returnDataType)
                ret = _shMemManager->shMemOutput(rowKey , freq , value , length);
            else
                ret = _shMemManager->shMemOutput(rowKey , length);

            if(ret == RET_SUCCESS)
                reply.set_shm_size(length);
            else
                reply.set_status_code(SHM_FAILED);
        }
        else
        {
            if(returnDataType)
            {
                reply.set_row_key(rowKey);
                reply.set_frequency(freq);
                reply.set_value(value);
            }
            else
                reply.set_row_key(rowKey);
        }
    }
#ifndef CSTEST
    if( AgentManager::getInstance()->find(agentID) )
        Initializer::getCodec().send(agentID , reply);
#endif
}

void CS4QEService::onQEQuery4ValueByIndex(uint32_t agentID,
                                          MessagePtr const& queryMsg)
{
    ReqColByDictIndexMsgPtr query =
        muduo::down_pointer_cast<ReqColByDictIndexMsg>(queryMsg);

    ReqColByDictIndexAck reply;
    uint32_t dbID = query->db_id();
    string tableName = query->table_name();
    string columnName = query->column_name();
    ColObjType colObj;
    if( RET_SUCCESS == parseCommonInfoOfQuery(query , reply , colObj) )
    {
        bool returnDataType = query->return_data_type();
        bool isLocal = query->is_local();
        size_t colDataType = colObj.second;
        reply.set_status_code(SUCCESS);
        string rowKey;
        string freq;
        string value;
        //string
        Uint64VecPtr posList = io::parseStr( query->index_vec() );
        if(colDataType == GROUPKEY_STRING)
        {
            DGroupKey<string>* groupKey = static_cast<DGroupKey<string>*>(colObj.first);
            reply.set_value_type(GROUPKEY_STRING);
            if(returnDataType)
                _groupKeyQE->executeQuery(*posList , *groupKey , rowKey , freq,
                                          value);
            else
                _groupKeyQE->executeQuery(*posList , *groupKey , rowKey);

        }
        else if(colDataType == GROUPKEY_INT)
        {
            DGroupKey<int>* groupKey = static_cast<DGroupKey<int>*>(colObj.first);
            reply.set_value_type(GROUPKEY_INT);
            if(returnDataType)
                _groupKeyQE->executeQuery(*posList , *groupKey , rowKey , freq,
                                          value);
            else
                _groupKeyQE->executeQuery(*posList , *groupKey , rowKey);
        }
        else
        {
            DGroupKey<double>* groupKey = static_cast<DGroupKey<double>*>(colObj.first);
            reply.set_value_type(GROUPKEY_DOUBLE);
            if(returnDataType)
                _groupKeyQE->executeQuery(*posList , *groupKey , rowKey , freq , value);
            else
                _groupKeyQE->executeQuery(*posList , *groupKey , rowKey);
        }

        if(isLocal)
        {
            UINT length;
            int ret;
            if(returnDataType)
                ret = _shMemManager->shMemOutput(rowKey , freq , value , length);
            else
                ret = _shMemManager->shMemOutput(rowKey , length);

            if(ret == RET_SUCCESS)
                reply.set_shm_size(length);
            else
                reply.set_status_code(SHM_FAILED);
        }
        else
        {
            if(returnDataType)
            {
                reply.set_row_key(rowKey);
                reply.set_frequency(freq);
                reply.set_value(value);
            }
            else
                reply.set_row_key(rowKey);
        }
    }
#ifndef CSTEST
    if( AgentManager::getInstance()->find(agentID) )
        Initializer::getCodec().send(agentID , reply);
#endif
}

void CS4QEService::onQEQuery4IndexByRowkey(uint32_t agentID,
                                           MessagePtr const& queryMsg)
{
    ReqDictIndexMsgPtr query = muduo::down_pointer_cast<ReqDictIndexMsg>(queryMsg);
    ReqDictIndexAck reply;
    DRowTablePtr rowTable;
    bool isLocal = query->is_local();
    if( RET_SUCCESS == parseCommonInfoOfQuery(query , reply , rowTable) )
    {
        std::string rowkeyStr = query->rowkeys();
        Uint64VecPtr rowkeys = io::parseStr(rowkeyStr);
        std::vector<uint64_t> indexes( ( rowTable->getValue(
                                        query->column_name(), *rowkeys) ) );
        StdStrPtr tmp( io::changeRetVal2Str(indexes) );
        if(isLocal)
        {
            UINT length;
            int ret = _shMemManager->shMemOutput(*tmp, length);
            if(ret == RET_SUCCESS)
                reply.set_shm_size(length);
            else
                reply.set_status_code(SHM_FAILED);
        }
        else
            reply.set_dict_index(*tmp);
    }
#ifndef CSTEST
    if( AgentManager::getInstance()->find(agentID) )
        Initializer::getCodec().send(agentID , reply);
#endif
}
