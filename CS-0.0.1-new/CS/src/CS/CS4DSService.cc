#include <string>
#include <sys/sysinfo.h>
#include <cassert>

#include <muduo/net/Callbacks.h>

#include <common/comm/AgentManager.h>

#include <boost/lexical_cast.hpp>
#include <boost/bind.hpp>

#include <CS/CS4DSService.h>
#include <CS/CS4DCAgent.h>
#include <CS/IndexOffset.h>
#include <CS/BitCompressedVector.h>
#include <CS/DGroupKey.h>
#include <CS/RWMutex.h>
#include <CS/Initializer.h>
#include <CS/CSServer.h>

#ifdef CSTEST
extern SysStatGetAck g_SysStatAck;
extern RTableCreateAck g_RtableCreateAck;
extern RTableSendAck g_RtableUpdateAck;
extern DRowTablePtr g_TestRowTable;
extern IndexSendMsg g_IndexSendMsg;
extern RawDataSendAck g_RawDataSendAck;
extern ColumnTable* g_ColumnTable;
extern UpdateDataSendAck g_UpdateDataSendAck;
extern IndexSendMsg g_IndexSendMsg1;
#endif

using namespace muduo;
extern MutexLock g_Lock;

CS4DSService::CS4DSService(CSServer* server):_server(server)
{
    Initializer::getDispatcher().registerMessageCallback(
        RawDataSendMsg::descriptor(),
        boost::bind(&CS4DSService::onCreateGroupKeyData , this , _1 , _2)
        );

    Initializer::getDispatcher().registerMessageCallback(
        RTableCreateMsg::descriptor(),
        boost::bind(&CS4DSService::onRTableCreate , this , _1 , _2)
        );

    Initializer::getDispatcher().registerMessageCallback(
        RTableSendMsg::descriptor(),
        boost::bind(&CS4DSService::onRTableUpdate , this , _1 , _2)
        );

    Initializer::getDispatcher().registerMessageCallback(
        UpdateDataSendMsg::descriptor(),
        boost::bind(&CS4DSService::onUpdateGroupKeyData , this , _1 , _2)
        );

    ProtobufCodec::registeMsg(MSG_DS_CS_RAW_DATA_SEND_CMD,
        "MSG_DS_CS_RAW_DATA_SEND");
    ProtobufCodec::registeMsg(MSG_CS_DS_RAW_DATA_SEND_ACK_CMD,
        "MSG_CS_DS_RAW_DATA_SEND_ACK");
    ProtobufCodec::registeMsg(MSG_DS_CS_RTABLE_CREATE_CMD,
        "MSG_DS_CS_RTABLE_CREATE");
    ProtobufCodec::registeMsg(MSG_CS_DS_RTABLE_CREATE_ACK_CMD,
        "MSG_CS_DS_RTABLE_CREATE_ACK");
    ProtobufCodec::registeMsg(MSG_DS_CS_RTABLE_SEND_CMD,
        "MSG_DS_CS_RTABLE_SEND");
    ProtobufCodec::registeMsg(MSG_CS_DS_RTABLE_SEND_ACK_CMD,
        "MSG_CS_DS_RTABLE_SEND_ACK");
    ProtobufCodec::registeMsg(MSG_DS_CS_UPDATE_DATA_SEND_CMD,
        "MSG_DS_CS_UPDATE_DATA_SEND");
    ProtobufCodec::registeMsg(MSG_CS_DS_UPDATE_DATA_SEND_ACK_CMD,
        "MSG_CS_DS_UPDATE_DATA_SEND_ACK");
}

void CS4DSService::onCreateGroupKeyData(uint32_t agentID,
                                        		 MessagePtr const& msg)
{
    (Initializer::getThreadPool()).run(
        boost::bind(&CS4DSService::doCreateGroupKeyData , this , agentID , msg) );
}

void CS4DSService::doCreateGroupKeyData(uint32_t agentID,
                                        		 MessagePtr const& msg)
{
    RawDataSendMsgPtr query =
        muduo::down_pointer_cast<RawDataSendMsg>(msg);

    UINT dbID = query->dbid();
    std::string tableName = query->tablename();
    std::string columnName = query->columnname();

    UINT indexOffsetSize = query->indexoffsets_size();
    IndexOffset* offset = new IndexOffset;
    for(UINT i = 0 ; i != indexOffsetSize ; ++i)
        offset->push_back( query->indexoffsets(i) );

    UINT postingSize = query->indexposting_size();
    BitCompressedVector* posting = new BitCompressedVector(postingSize);
    for(UINT i = 0 ; i != postingSize ; ++i)
        posting->push_back( query->indexposting(i) );

    UINT dictSize = query->dicvalue_size();
    DGroupKey<std::string>* strColumn = NULL;
    DGroupKey<int>* intColumn = NULL;
    DGroupKey<double>* doubleColumn = NULL;

    RawDataSendAck reply4DS;
    reply4DS.set_statuscode(UNKNOWN_DICT_TYPE);
    reply4DS.set_taskid(query->taskid());
    reply4DS.set_columnname(columnName);

    Dictionary<std::string>* strTypeDict = NULL;
    Dictionary<int>* intTypeDict = NULL;
    Dictionary<double>* doubleTypeDict = NULL;
    {//TODO
        MutexLockGuard tmpLock(g_Lock);
#ifndef SPEEDTEST
        LOG_INFO << "############################";
        LOG_INFO << "in create group-key begin, table name: " << tableName
            << " column name: " << columnName;
        LOG_INFO << "############################";
#endif
    }

    switch( query->columntype() )
    {
    case PROTO_STRING:

        strTypeDict = new Dictionary<std::string>;
        for(UINT i = 0 ; i != dictSize ; ++i)
            strTypeDict->push_back( ( query->dicvalue(i) ).strvalue() );

        strColumn = new DGroupKey<std::string>(columnName , 0 , GROUPKEY_STRING);
        strColumn->constructThreeVector(strTypeDict , offset , posting);
        break;

    case PROTO_INT:

        intTypeDict = new Dictionary<int>;
        for(UINT i = 0 ; i != dictSize ; ++i)
            intTypeDict->push_back( ( query->dicvalue(i) ).ivalue() );

        intColumn = new DGroupKey<int>(columnName , 0 , GROUPKEY_INT);
        intColumn->constructThreeVector(intTypeDict , offset , posting);
        break;

    case PROTO_DOUBLE:

        doubleTypeDict = new Dictionary<double>;
        for(UINT i = 0 ; i != dictSize ; ++i)
            doubleTypeDict->push_back( ( query->dicvalue(i) ).dvalue() );

        doubleColumn = new DGroupKey<double>(columnName , 0 , GROUPKEY_DOUBLE);
        doubleColumn->constructThreeVector(doubleTypeDict , offset , posting);
        break;

    default:
#ifdef CSDEBUG
        LOG_INFO << "Unknown type of dictionary";
#endif
        if(AgentManager::getInstance()->find( agentID ))
            Initializer::getCodec().send(agentID , reply4DS);
        return;
    }

    {
        MutexLockGuard lock(_tbCreateMutex);
        if( _dbID2TManager.find(dbID) == _dbID2TManager.end() )
        {
            TableManagerPtr tbManager(new TableManager);
            _dbID2TManager[dbID] = tbManager;
        }
        if(NULL == _dbID2TManager[dbID]->getColumnTable(tableName))
        {
            _dbID2TManager[dbID]->createColumnTable(tableName);
        }
    }

    ColumnTable* columnTable = _dbID2TManager[dbID]->getColumnTable(tableName);
    IndexSendMsg reply4DC;
    reply4DC.set_dbid(dbID);
    reply4DC.set_tablename(tableName);
    reply4DC.set_columnname(columnName);
    if(strColumn != NULL)
    {
        columnTable->insertOneDGroupKey(strColumn , strColumn->getName(),
            GROUPKEY_STRING);
#ifdef CSTEST
        g_ColumnTable = columnTable;
#endif
        INDEX_BORDER* indexBorder = reply4DC.mutable_colindexborder();
        INDEX_BORDER_DICT_TYPE dictType = INDEX_BORDER_DICT_TYPE_VARCHAR;
        indexBorder->set_dicttype(dictType);
        indexBorder->mutable_dictlower()->
            set_strvalue(strColumn->getDictionary()->get(0));
        uint64_t rows = strColumn->getDictionary()->getRows();
        {//TODO
            MutexLockGuard tmpLock(g_Lock);
#ifndef SPEEDTEST
            LOG_INFO << "############################";
            LOG_INFO << "in create group-key finish, table name: " << tableName
                << " column name: " << columnName << " rows: " << rows;
            LOG_INFO << "############################";
#endif
        }
        indexBorder->mutable_dictupper()->
            set_strvalue(strColumn->getDictionary()->get(rows - 1));
        indexBorder->set_entryupper(rows - 1);
        indexBorder->set_entrylower(0);
    }
    else if(intColumn != NULL)
    {
        columnTable->insertOneDGroupKey(intColumn , intColumn->getName(),
            GROUPKEY_INT);
        INDEX_BORDER* indexBorder = reply4DC.mutable_colindexborder();
        INDEX_BORDER_DICT_TYPE dictType = INDEX_BORDER_DICT_TYPE_INTTYPE;
        indexBorder->set_dicttype(dictType);
        indexBorder->mutable_dictlower()->
            set_ivalue(intColumn->getDictionary()->get(0));
        uint64_t rows = intColumn->getDictionary()->getRows();
        indexBorder->mutable_dictupper()->
            set_ivalue(intColumn->getDictionary()->get(rows - 1));
        indexBorder->set_entryupper(rows - 1);
        indexBorder->set_entrylower(0);
    }
    else
    {
        columnTable->insertOneDGroupKey(doubleColumn , doubleColumn->getName(),
            GROUPKEY_DOUBLE);
        INDEX_BORDER* indexBorder = reply4DC.mutable_colindexborder();
        INDEX_BORDER_DICT_TYPE dictType = INDEX_BORDER_DICT_TYPE_DOUBLETYPE;
        indexBorder->set_dicttype(dictType);
        indexBorder->mutable_dictlower()->
            set_dvalue(doubleColumn->getDictionary()->get(0));
        uint64_t rows = doubleColumn->getDictionary()->getRows();
        indexBorder->mutable_dictupper()->
            set_dvalue(doubleColumn->getDictionary()->get(rows - 1));
        indexBorder->set_entryupper(rows - 1);
        indexBorder->set_entrylower(0);
    }
    reply4DS.set_statuscode(SUCCESS);
#ifndef CSTEST
    if(AgentManager::getInstance()->find( agentID ))
        Initializer::getCodec().send(agentID , reply4DS);
#else
    g_RawDataSendAck = reply4DS;
#endif
    if(query->sliceno() == query->slicenum())
    {
#ifndef CSTEST
        if( AgentManager::getInstance()
                                ->find( _server->getCS4DCAgent()->getID() ) )
            Initializer::getCodec().send( _server->getCS4DCAgent()->getID(),
                                         reply4DC);//TODO
        {
            MutexLockGuard tmpLock(g_Lock);
            LOG_INFO << "=========================================";
            LOG_INFO << "db id: " <<dbID << " table name: " << tableName
                << " column name: " << columnName;
            LOG_INFO << "=========================================";
        }
#else
        g_IndexSendMsg = reply4DC;
#endif
    }
}

void CS4DSService::onUpdateGroupKeyData(uint32_t agentID,
                                        		  MessagePtr const& msg)
{
    (Initializer::getThreadPool()).run(
        boost::bind(&CS4DSService::doUpdateGroupKeyData , this , agentID , msg) );
}

void CS4DSService::doUpdateGroupKeyData(uint32_t agentID,
                                      			  MessagePtr const& msg)
{
    UpdateDataSendMsgPtr query =
        muduo::down_pointer_cast<UpdateDataSendMsg>(msg);
    UINT dbID = query->dbid();
    std::string tableName = query->tablename();
    std::string columnName = query->columnname();
    UINT indexOffsetSize = query->indexoffsets_size();
    IndexOffset* offset = new IndexOffset;
    for(UINT i = 0 ; i != indexOffsetSize ; ++i)
        offset->push_back( query->indexoffsets(i) );
    UINT postingSize = query->indexposting_size();
    BitCompressedVector* posting = new BitCompressedVector(postingSize);
    for(UINT i = 0 ; i != postingSize ; ++i)
        posting->push_back( query->indexposting(i) );
    UINT dictSize = query->dicvalue_size();
    DGroupKey<std::string>* strColumn = NULL;
    DGroupKey<int>* intColumn = NULL;
    DGroupKey<double>* doubleColumn = NULL;

    UpdateDataSendAck reply4DS;
    reply4DS.set_statuscode(UNKNOWN_DICT_TYPE);
    reply4DS.set_dbid(dbID);
    reply4DS.set_tablename(tableName);
    reply4DS.set_columnname(columnName);
    reply4DS.set_taskid( query->taskid() );
    reply4DS.set_sliceno( query->sliceno() );

    Dictionary<std::string>* strTypeDict = NULL;
    Dictionary<int>* intTypeDict = NULL;
    Dictionary<double>* doubleTypeDict = NULL;
    {//TODO
        MutexLockGuard tmpLock(g_Lock);
#ifndef SPEEDTEST
        LOG_INFO << "#########################";
        LOG_INFO << "in update group-key begin, table name: " << tableName
            << " column name: " << columnName;
        LOG_INFO << "#########################";
#endif
    }

    switch( query->columntype() )
    {
    case PROTO_STRING:

        strTypeDict = new Dictionary<std::string>;
        for(UINT i = 0 ; i != dictSize ; ++i)
            strTypeDict->push_back( ( query->dicvalue(i) ).strvalue() );

        strColumn = new DGroupKey<std::string>(columnName , 0 , GROUPKEY_STRING);
        strColumn->constructThreeVector(strTypeDict , offset , posting);
        break;

    case PROTO_INT:

        intTypeDict = new Dictionary<int>;
        for(UINT i = 0 ; i != dictSize ; ++i)
            intTypeDict->push_back( ( query->dicvalue(i) ).ivalue() );

        intColumn = new DGroupKey<int>(columnName , 0 , GROUPKEY_INT);
        intColumn->constructThreeVector(intTypeDict , offset , posting);
        break;

    case PROTO_DOUBLE:

        doubleTypeDict = new Dictionary<double>;
        for(UINT i = 0 ; i != dictSize ; ++i)
            doubleTypeDict->push_back( ( query->dicvalue(i) ).dvalue() );

        doubleColumn = new DGroupKey<double>(columnName , 0 , GROUPKEY_DOUBLE);
        doubleColumn->constructThreeVector(doubleTypeDict , offset , posting);
        break;

    default:
#ifdef CSDEBUG
        LOG_INFO << "Unknown type of dictionary";
#endif
        if(AgentManager::getInstance()->find( agentID ))
            Initializer::getCodec().send(agentID , reply4DS);
        return;
    }

    std::vector<uint64_t> xVector;
    ColumnTable* columnTable = _dbID2TManager[dbID]->getColumnTable(tableName);
    assert(columnTable != NULL);
    //(columnTable->getColumnRWLock())->wrLock();
    IndexSendMsg reply4DC;
    reply4DC.set_dbid(dbID);
    reply4DC.set_tablename(tableName);
    reply4DC.set_columnname(columnName);
    INDEX_BORDER* indexBorder = reply4DC.mutable_colindexborder();
    UINT mergedSize = 0;
    if(strColumn != NULL)
    {
        xVector = columnTable->updateOneDGroupKey(strColumn , columnName,
            GROUPKEY_STRING);
        if(xVector.empty())
            return;
        DGroupKey<std::string>* mergedGroupKey =
            (DGroupKey<std::string>*)(columnTable->getOneDGroupKey(columnName)).first;
        INDEX_BORDER_DICT_TYPE dictType = INDEX_BORDER_DICT_TYPE_VARCHAR;
        MSG_CS_DS_UPDATE_DATA_SEND_ACK_COL_TYPE colType =
            MSG_CS_DS_UPDATE_DATA_SEND_ACK_COL_TYPE_VARCHAR;
        reply4DS.set_columntype(colType);
        mergedSize = mergedGroupKey->getDictionary()->getRows();
        {//TODO
            MutexLockGuard tmpLock(g_Lock);
#ifndef SPEEDTEST
            LOG_INFO << "#########################";
            LOG_INFO << "in update group-key finish, table name: " << tableName
                << " column name: " << columnName << " rows: " << mergedSize;
            LOG_INFO << "#########################";
#endif
        }
        for(UINT i = 0 ; i != mergedSize ; ++i)
        {
            ( reply4DS.add_dicvalue() )->set_strvalue(
                mergedGroupKey->getDictionary()->get(i) );
        }

        indexBorder->set_dicttype(dictType);
        indexBorder->mutable_dictlower()->
            set_strvalue(mergedGroupKey->getDictionary()->get(0));
        indexBorder->mutable_dictupper()->set_strvalue(
            mergedGroupKey->getDictionary()->get(mergedSize - 1));
#ifdef CSTEST
        g_ColumnTable = columnTable;
#endif
    }
    else if(intColumn != NULL)
    {
        xVector = columnTable->updateOneDGroupKey(intColumn , columnName,
            GROUPKEY_INT);
        if(xVector.empty())
            return;
        DGroupKey<int>* mergedGroupKey =
            (DGroupKey<int>*)(columnTable->getOneDGroupKey(columnName)).first;
        INDEX_BORDER_DICT_TYPE dictType = INDEX_BORDER_DICT_TYPE_INTTYPE;
        MSG_CS_DS_UPDATE_DATA_SEND_ACK_COL_TYPE colType =
            MSG_CS_DS_UPDATE_DATA_SEND_ACK_COL_TYPE_INTTYPE;
        reply4DS.set_columntype(colType);
        mergedSize = mergedGroupKey->getDictionary()->getRows();
        for(int i = 0 ; i != mergedSize ; ++i)
        {
            ( reply4DS.add_dicvalue() )->set_ivalue(
                mergedGroupKey->getDictionary()->get(i) );
        }

        indexBorder->set_dicttype(dictType);
        indexBorder->mutable_dictlower()->
            set_ivalue(mergedGroupKey->getDictionary()->get(0));
        indexBorder->mutable_dictupper()->set_ivalue(
            mergedGroupKey->getDictionary()->get(mergedSize - 1));
    }
    else
    {
        xVector = columnTable->updateOneDGroupKey(doubleColumn , columnName,
            GROUPKEY_DOUBLE);
        if(xVector.empty())
            return;
        DGroupKey<double>* mergedGroupKey =
            (DGroupKey<double>*)(columnTable->getOneDGroupKey(columnName)).first;
        INDEX_BORDER_DICT_TYPE dictType = INDEX_BORDER_DICT_TYPE_DOUBLETYPE;
        MSG_CS_DS_UPDATE_DATA_SEND_ACK_COL_TYPE colType =
            MSG_CS_DS_UPDATE_DATA_SEND_ACK_COL_TYPE_DOUBLETYPE;
        reply4DS.set_columntype(colType);
        mergedSize = mergedGroupKey->getDictionary()->getRows();
        for(UINT i = 0 ; i != mergedSize ; ++i)
        {
            ( reply4DS.add_dicvalue() )->set_dvalue(
                mergedGroupKey->getDictionary()->get(i) );
        }
        indexBorder->set_dicttype(dictType);
        indexBorder->mutable_dictlower()->
            set_dvalue(doubleColumn->getDictionary()->get(0));
        indexBorder->mutable_dictupper()->set_dvalue(
            doubleColumn->getDictionary()->get(mergedSize - 1));
    }
    indexBorder->set_entryupper(mergedSize - 1);
    indexBorder->set_entrylower(0);
    //(columnTable->getColumnRWLock())->unlock();
    for(UINT i = 0 ; i != xVector.size() ; ++i)
        reply4DS.add_xvector(xVector[i]);
    reply4DS.set_statuscode(SUCCESS);
#ifndef CSTEST
    if( AgentManager::getInstance()->find(agentID) )
        Initializer::getCodec().send(agentID , reply4DS);
#else
    g_UpdateDataSendAck = reply4DS;
#endif
    if(query->sliceno() == query->slicenum())
    {
#ifndef CSTEST
        if( AgentManager::getInstance()->
                                    find( _server->getCS4DCAgent()->getID() ) )
            Initializer::getCodec().send(_server->getCS4DCAgent()->getID(),
                                         reply4DC);
        {
            MutexLockGuard tmpLock(g_Lock);
            LOG_INFO << "=========================================";
            LOG_INFO << "db id: " <<dbID << " table name: " << tableName
                << " column name: " << columnName;
            LOG_INFO << "=========================================";
        }
#else
        g_IndexSendMsg1 = reply4DC;
#endif
    }
}

void CS4DSService::onRTableCreate(uint32_t agentID,
                                		MessagePtr const& msg)
{
    (Initializer::getThreadPool()).run(
        boost::bind(&CS4DSService::doRTableCreate , this , agentID , msg) );
}

void CS4DSService::doRTableCreate(uint32_t agentID,
                                  		MessagePtr const& msg)
{
	RTableCreateMsgPtr query = muduo::down_pointer_cast<RTableCreateMsg>(msg);
	UINT dbID = query->dbid();
	std::string tableName = query->tablename();
	UINT attributeCount = query->attributecount();
	std::string key = boost::lexical_cast<std::string>(dbID) + tableName;
	RTableCreateAck reply;
	reply.set_statuscode(SUCCESS);
	{
		MutexLockGuard tmpLock(_rtableCreateMutex);
		if( _dbID2RTable.find(key) == _dbID2RTable.end() )
		{
			DRowTablePtr rtable(new DRowTable(attributeCount , tableName , 0));
			_dbID2RTable[key] = rtable;
		}
	}
	std::string columnName;
	std::vector<uint64_t> tmpEntryList;
	int rows = -1;
	tmpEntryList.reserve(AVERAGE_ROW_NUM);
	for(int i = 0 ; i != query->columnrtables_size() ; ++i)
	{
		MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE const& singleColumn
			= query->columnrtables(i);
		columnName = singleColumn.columnname();
		rows = singleColumn.entrylist_size();
		{//TODO
#ifndef SPEEDTEST
			MutexLockGuard tmpLock(g_Lock);
            LOG_INFO << "############################";
			LOG_INFO << "in RTable Create, table name: " << tableName
			<< " column name: " << columnName << " rows: " << rows;
            LOG_INFO << "############################";
#endif
		}
		tmpEntryList.clear();
		for(int j = 0 ; j != rows ; ++j)
			tmpEntryList.push_back( singleColumn.entrylist(j) );
		_dbID2RTable[key]->fillOneColumn(columnName , rows , tmpEntryList);
	}
	reply.set_taskid(query->taskid());
#ifndef CSTEST
    if( AgentManager::getInstance()->find(agentID) )
        Initializer::getCodec().send(agentID , reply);
#else
	g_TestRowTable = _dbID2RTable[key];
	g_RtableCreateAck = reply;
#endif
}

void CS4DSService::onRTableUpdate(uint32_t agentID,
                                		 MessagePtr const& msg)
{
    (Initializer::getThreadPool()).run(
        boost::bind(&CS4DSService::doRTableUpdate , this , agentID , msg) );
}

void CS4DSService::doRTableUpdate(uint32_t agentID,
                                  		 MessagePtr const& msg)
{
	RTableSendMsgPtr query = muduo::down_pointer_cast<RTableSendMsg>(msg);
	int taskID = query->taskid();
	int dbID = query->dbid();
	std::string tableName = query->tablename();
	std::string columnName = query->columnname();
	{//TODO
		MutexLockGuard tmpLock(g_Lock);
#ifndef SPEEDTEST
        LOG_INFO << "#######################";
		LOG_INFO << "in RTable Update begin, table name: " << tableName
		<<" column name: " << columnName;
        LOG_INFO << "#######################";
#endif
	}
	UINT xVecSize = query->xvector_size();
	UINT newRowTableSize = query->rowtable_size();
	std::vector<uint64_t> xVector;
	xVector.reserve(xVecSize);
	std::vector<uint64_t> appendVec;
	appendVec.reserve(newRowTableSize);
	for(UINT i = 0 ; i != xVecSize ; ++i)
		xVector.push_back(query->xvector(i));
	for(UINT j = 0 ; j != newRowTableSize ; ++j)
		appendVec.push_back( query->rowtable(j).entry() );
	std::string key = boost::lexical_cast<std::string>(dbID) + tableName;
	RTableSendAck reply;
	reply.set_taskid(taskID);
	reply.set_columnname(columnName);
	reply.set_statuscode(NO_RTABLE_OF_THIS_TABLE);
	DRowTablePtr tmpRowTable;
	if( _dbID2RTable.find(key) != _dbID2RTable.end() )
	{
		tmpRowTable = _dbID2RTable[key];
		tmpRowTable->refresh(columnName , xVector);
		tmpRowTable->updateOneColumn(columnName , newRowTableSize , appendVec);
		{//TODO
			MutexLockGuard tmpLock(g_Lock);
#ifndef SPEEDTEST
            LOG_INFO << "###########################";
			LOG_INFO << "in RTable Update, table name: " << tableName
			<< " column name: " << columnName << " rows: " <<
            tmpRowTable->getColumnRows(columnName) << " the key is: " << key;
            LOG_INFO << "###########################";
#endif
		}
		reply.set_statuscode(SUCCESS);
	}
#ifndef CSTEST
    if( AgentManager::getInstance()->find(agentID) )
        Initializer::getCodec().send(agentID , reply);
#else
	g_RtableUpdateAck = reply;
	g_TestRowTable = _dbID2RTable[key];
#endif
}
