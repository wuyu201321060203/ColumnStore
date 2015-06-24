#ifndef CS4QESERVICE_H
#define CS4QESERVICE_H

#include <string>
#include <vector>
#include <utility>

#include <boost/lexical.hpp>

#include "Config.h"
#include "GroupKeyQueryEngineProxy.h"
#include "ShMemManager.h"
#include "CS4DSService.h"

class CS4QEService
{
public:

    CS4QEService(CSServer* csserver , std::string filePath);

    void onQEQuery4ValueByFilter(uint32_t agentID , MessagePtr const& queryMsg);
    void onQEQuery4ValueByIndex(uint32_t agentID , MessagePtr const& queryMsg);
    void onQEQuery4IndexByRowkey(uint32_t agentID , MessagePtr const& queryMsg);

private:

    typedef std::pair<void* , size_t> ColObjType;

    template<typename T , typename U , typename V>
    static int parseCommonInfoOfQuery(T const& query , U const& reply , V& colobj)
    {
        int ret = RET_FAIL;
        uint32_t dbID = query->db_id();
        std::string tableName = query->table_name();
        std::string columnName = query->column_name();
        CS4DSService* dataStorageService = _csserver->getDataStorageService();
        if( (dataStorageService->_dbID2TManager).find(dbID)
                                    == dataStorageService->_dbID2TManager.end() )
            reply.set_status_code(UNEXISTED_DATABASE);
        else
        {
            TableManagerPtr tbManager = (dataStorageService->_dbID2TManager)[dbID];
            ColumnTable* table = tbManager->getColumnTable(tableName);
            if(NULL ==  table)
                reply.set_status_code(UNEXISTED_TABLE);
            else
            {
                if( -1 == table->getPos(columnName) )
                    reply.set_status_code(UNEXISTED_COL);
                else
                {
                    ret = RET_SUCCESS;
                    colobj = table->getOneDGroupKey(columnName);
                }
            }
        }
        return ret;
    }

    static int parseCommonInfoOfQuery(ReqDictIndexMsgPtr const& query,
                                      ReqDictIndexAck const& reply,
                                      DRowTablePtr& obj)
    {
        int ret = RET_FAIL;
        uint32_t dbID = query->db_id();
        std::string tableName = query->table_name();
        std::string columnName = query->column_name();
        std::string key = boost::lexical<std::string>(dbID) + tableName;
        CS4DSService* dataStorageService = _csserver->getDataStorageService();
        if( (dataStorageService->_dbID2RTable).find(key) ==
                                        (dataStorageService->_dbID2RTable).end() )
            reply.set_status_code(NO_RTABLE_OF_THIS_TABLE);
        else
        {
            DRowTablePtr rowTable = (dataStorageService->_dbID2RTable)[key];
            if( -1 == rowTable->caculatePos(columnName) )
                reply.set_status_code(UNEXISTED_COL);
            else
            {
                reply.set_status_code(SUCCESS);
                obj = rowTable;
                ret = RET_SUCCESS;
            }
        }
        return ret;
    }

private:

    CSServer* _csserverPtr;
    GroupKeyQueryEngineProxyPtr _groupKeyQE;
    ShMemManagerPtr _shMemManager;
};

#endif