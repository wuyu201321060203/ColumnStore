#include <gtest/gtest.h>
#include <CS/CSServer.h>
#include <CS/Initializer.h>
#include <muduo/net/InetAddress.h>
#include <muduo/net/TcpConnection.h>
#include <unistd.h>
#include <iostream>
#include <CS/Config.h>
#include <vector>

SysStatGetAck g_SysStatAck;
RTableCreateAck g_RtableCreateAck;
RTableSendAck g_RtableUpdateAck;
DRowTablePtr g_TestRowTable;
IndexSendMsg g_IndexSendMsg;
RawDataSendAck g_RawDataSendAck;
ColumnTable* g_ColumnTable;
UpdateDataSendAck g_UpdateDataSendAck;
IndexSendMsg g_IndexSendMsg1;
//ColumnTable* g_ColumnTable1;

using namespace muduo;
using namespace muduo::net;

TEST(CSServerTest , onSysStatQuery)
{
    CSServer server;
    char* config[8] = {"test" , "1" , "9878" , "9879" , "9880" ,  "127.0.0.1",
        "9881" , "127.0.0.1"};
    Initializer::init(8 , config);
    TcpConnectionPtr conn;
    InetAddress localAddr(10);
    InetAddress remoteAddr(100);
    int socketfd = ::socket(AF_INET , SOCK_STREAM , IPPROTO_TCP);
    conn.reset( new TcpConnection(&Initializer::getEventLoop(),
        "conn" , socketfd , localAddr , remoteAddr) );
    SysStatGetMsg* tmp = new SysStatGetMsg;
    MessagePtr msg(tmp);
    Timestamp time;
    server.onSysStatQuery(conn , msg , time);
    sleep(3);
    ::SINGLE_NODE_INFO const& info = g_SysStatAck.nodesysinfo();
    EXPECT_EQ(1 , info.nodeid());
    EXPECT_EQ("OK" , info.nodestatus());
    EXPECT_EQ("127.0.0.1" , info.nodeip());
    EXPECT_EQ(9878 , info.nodeport());
    EXPECT_EQ(16 , info.core());
    std::cout << "memsize: " << info.memsize() << "\n";
}

TEST(CSServerTest , onRTableCreate)
{
	CSServer server;
	TcpConnectionPtr conn;
	InetAddress localAddr(10);
	InetAddress remoteAddr(100);
	int socketfd = ::socket(AF_INET , SOCK_STREAM , IPPROTO_TCP);
	conn.reset( new TcpConnection(&Initializer::getEventLoop(),
				"conn" , socketfd , localAddr , remoteAddr) );
	RTableCreateMsg* tmp = new RTableCreateMsg;
	tmp->set_taskid(1);
	tmp->set_dbid(2);
	tmp->set_tablename("test");
	tmp->set_attributecount(2);
	MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE* columnTable = tmp->add_columnrtables();
	columnTable->set_columnname("col1");
	columnTable->add_entrylist(10);
	columnTable->add_entrylist(11);
    MessagePtr msg(tmp);
	Timestamp time;
	server.onRTableCreate(conn , msg , time);
	sleep(3);
    EXPECT_EQ(SUCCESS , g_RtableCreateAck.statuscode());
	EXPECT_EQ(1 , g_RtableCreateAck.taskid());
	EXPECT_EQ(2 , g_TestRowTable->getColumnRows("col1"));
    std::vector<uint64_t> temp;
	temp.push_back(0);
	temp.push_back(1);
	std::vector<uint64_t> result = g_TestRowTable->getValue("col1" , temp);
	EXPECT_EQ(10 , result[0]);
	EXPECT_EQ(11 , result[1]);

    RTableCreateMsg* tmp1 = new RTableCreateMsg;
	tmp1->set_taskid(1);
	tmp1->set_dbid(2);
	tmp1->set_tablename("test");
	tmp1->set_attributecount(2);
	MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE* columnTable1 = tmp1->add_columnrtables();
	columnTable1->set_columnname("col2");
	columnTable1->add_entrylist(12);
	columnTable1->add_entrylist(13);
    MessagePtr msg1(tmp1);
	Timestamp time1;
	server.onRTableCreate(conn , msg1 , time1);
	sleep(3);
    EXPECT_EQ(SUCCESS , g_RtableCreateAck.statuscode());
	EXPECT_EQ(1 , g_RtableCreateAck.taskid());
	EXPECT_EQ(2 , g_TestRowTable->getColumnRows("col2"));
	std::vector<uint64_t> result1 = g_TestRowTable->getValue("col2" , temp);
	EXPECT_EQ(12 , result1[0]);
	EXPECT_EQ(13 , result1[1]);
    EXPECT_EQ(2 , g_TestRowTable->getColumnRows("col2"));
	result1 = g_TestRowTable->getValue("col1" , temp);
	EXPECT_EQ(10 , result1[0]);
	EXPECT_EQ(11 , result1[1]);
}

TEST(CSServerTest , onRTableUpdate)
{
    CSServer server;
    TcpConnectionPtr conn;
    InetAddress localAddr(10);
    InetAddress remoteAddr(100);
    int socketfd = ::socket(AF_INET , SOCK_STREAM , IPPROTO_TCP);
    conn.reset( new TcpConnection(&Initializer::getEventLoop(),
        "conn" , socketfd , localAddr , remoteAddr) );
    RTableCreateMsg* tmp1 = new RTableCreateMsg;
    tmp1->set_taskid(1);
    tmp1->set_dbid(2);
    tmp1->set_tablename("test");
    tmp1->set_attributecount(2);
    MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE* columnTable = tmp1->add_columnrtables();
    columnTable->set_columnname("col1");
    columnTable->add_entrylist(0);
    columnTable->add_entrylist(1);
    MessagePtr msg1(tmp1);
    Timestamp time1;
    server.onRTableCreate(conn , msg1 , time1);
    sleep(3);
    tmp1 = new RTableCreateMsg;
    tmp1->set_taskid(1);
    tmp1->set_dbid(2);
    tmp1->set_tablename("test");
    tmp1->set_attributecount(2);
    columnTable = tmp1->add_columnrtables();
    columnTable->set_columnname("col2");
    columnTable->add_entrylist(0);
    columnTable->add_entrylist(1);
    MessagePtr msg2(tmp1);
    server.onRTableCreate(conn , msg2 , time1);
    sleep(3);

    std::vector<uint64_t> temp;
    temp.push_back(0);
    temp.push_back(1);
    temp.push_back(2);
    temp.push_back(3);
    EXPECT_EQ(SUCCESS , g_RtableCreateAck.statuscode());
	EXPECT_EQ(1 , g_RtableCreateAck.taskid());
	EXPECT_EQ(2 , g_TestRowTable->getColumnRows("col2"));
	std::vector<uint64_t> result11 = g_TestRowTable->getValue("col2" , temp);
	EXPECT_EQ(0 , result11[0]);
	EXPECT_EQ(1 , result11[1]);

    RTableSendMsg* tmp = new RTableSendMsg;
    tmp->set_taskid(1);
    tmp->set_dbid(2);
    tmp->set_tablename("test");
    tmp->set_columnname("col1");
    ::ROWKEY_ENTRY* appendRows = tmp->add_rowtable();
    appendRows->set_entry(20);
    appendRows = tmp->add_rowtable();
    appendRows->set_entry(21);
    tmp->add_xvector(1);
    tmp->add_xvector(1);
    MessagePtr msg(tmp);
    Timestamp time;
    server.onRTableUpdate(conn , msg , time);
    sleep(3);
    EXPECT_EQ(SUCCESS , g_RtableUpdateAck.statuscode());
    EXPECT_EQ(1 , g_RtableUpdateAck.taskid());
    EXPECT_EQ(4 , g_TestRowTable->getColumnRows("col1"));
    EXPECT_EQ("test" , g_TestRowTable->getTableName());
    std::vector<uint64_t> result = g_TestRowTable->getValue("col1" , temp);
    EXPECT_EQ(1 , result[0]);
    EXPECT_EQ(2 , result[1]);
    EXPECT_EQ(20 , result[2]);
    EXPECT_EQ(21 , result[3]);

    tmp = new RTableSendMsg;
    tmp->set_taskid(1);
    tmp->set_dbid(2);
    tmp->set_tablename("test");
    tmp->set_columnname("col2");
    appendRows = tmp->add_rowtable();
    appendRows->set_entry(22);
    appendRows = tmp->add_rowtable();
    appendRows->set_entry(23);
    tmp->add_xvector(1);
    tmp->add_xvector(1);
    MessagePtr msg11(tmp);
    server.onRTableUpdate(conn , msg11 , time);
    sleep(3);
    EXPECT_EQ(SUCCESS , g_RtableUpdateAck.statuscode());
    EXPECT_EQ(1 , g_RtableUpdateAck.taskid());
    EXPECT_EQ(4 , g_TestRowTable->getColumnRows("col2"));
    EXPECT_EQ("test" , g_TestRowTable->getTableName());
    std::vector<uint64_t> result1 = g_TestRowTable->getValue("col2" , temp);
    EXPECT_EQ(1 , result1[0]);
    EXPECT_EQ(2 , result1[1]);
    EXPECT_EQ(22 , result1[2]);
    EXPECT_EQ(23 , result1[3]);
}

TEST(CSServerTest , onGroupKeyCreate)
{
    CSServer server;
    TcpConnectionPtr conn;
    InetAddress localAddr(10);
    InetAddress remoteAddr(100);
    int socketfd = ::socket(AF_INET , SOCK_STREAM , IPPROTO_TCP);
    conn.reset( new TcpConnection(&Initializer::getEventLoop(),
        "conn" , socketfd , localAddr , remoteAddr) );
    RawDataSendMsg* tmp = new RawDataSendMsg;
    tmp->set_taskid(1);
    tmp->set_dbid(2);
    tmp->set_tablename("test");
    tmp->set_columnname("col1");
    tmp->set_columntype(MSG_DS_CS_RAW_DATA_SEND_COL_TYPE_VARCHAR);
    (tmp->add_dicvalue())->set_strvalue("a");
    (tmp->add_dicvalue())->set_strvalue("b");
    (tmp->add_dicvalue())->set_strvalue("c");
    tmp->add_indexoffsets(0);
    tmp->add_indexoffsets(1);
    tmp->add_indexoffsets(3);
    tmp->add_indexoffsets(4);
    tmp->add_indexposting(10);
    tmp->add_indexposting(11);
    tmp->add_indexposting(12);
    tmp->add_indexposting(13);
    tmp->set_sliceno(1);
    tmp->set_slicenum(1);
    MessagePtr msg(tmp);
    Timestamp time;
    server.onCreateGroupKeyData(conn , msg , time);
    sleep(3);
    EXPECT_EQ(1 , g_RawDataSendAck.taskid());
    EXPECT_EQ(SUCCESS , g_RawDataSendAck.statuscode());
    EXPECT_EQ("col1" , g_RawDataSendAck.columnname());
    EXPECT_EQ(2 , g_IndexSendMsg.dbid());
    EXPECT_EQ("test" , g_IndexSendMsg.tablename());
    ::INDEX_BORDER* border =  g_IndexSendMsg.mutable_colindexborder();
    EXPECT_EQ(INDEX_BORDER_DICT_TYPE_VARCHAR , border->dicttype());
    EXPECT_EQ("c" , (border->mutable_dictupper())->strvalue());
    EXPECT_EQ("a" , (border->mutable_dictlower())->strvalue());
    EXPECT_EQ(2, border->entryupper());
    EXPECT_EQ(0, border->entrylower());
    g_ColumnTable->print();
}

TEST(CSServerTest , onGroupKeyUpdate)
{
    CSServer server;
    TcpConnectionPtr conn;
    InetAddress localAddr(10);
    InetAddress remoteAddr(100);
    int socketfd = ::socket(AF_INET , SOCK_STREAM , IPPROTO_TCP);
    conn.reset( new TcpConnection(&Initializer::getEventLoop(),
        "conn" , socketfd , localAddr , remoteAddr) );
    RawDataSendMsg* tmp = new RawDataSendMsg;
    tmp->set_taskid(1);
    tmp->set_dbid(2);
    tmp->set_tablename("test");
    tmp->set_columnname("col1");
    tmp->set_columntype(MSG_DS_CS_RAW_DATA_SEND_COL_TYPE_VARCHAR);
    (tmp->add_dicvalue())->set_strvalue("a");
    (tmp->add_dicvalue())->set_strvalue("c");
    (tmp->add_dicvalue())->set_strvalue("d");
    tmp->add_indexoffsets(0);
    tmp->add_indexoffsets(1);
    tmp->add_indexoffsets(3);
    tmp->add_indexoffsets(4);
    tmp->add_indexposting(10);
    tmp->add_indexposting(11);
    tmp->add_indexposting(12);
    tmp->add_indexposting(13);
    tmp->set_sliceno(1);
    tmp->set_slicenum(2);
    MessagePtr msg(tmp);
    Timestamp time;
    server.onCreateGroupKeyData(conn , msg , time);
    sleep(3);
    g_ColumnTable->print();
    UpdateDataSendMsg* tmp1 = new UpdateDataSendMsg;
    tmp1->set_taskid(1);
    tmp1->set_dbid(2);
    tmp1->set_tablename("test");
    tmp1->set_columnname("col1");
    tmp1->set_columntype(MSG_DS_CS_UPDATE_DATA_SEND_COL_TYPE_VARCHAR);
    (tmp1->add_dicvalue())->set_strvalue("b");
    (tmp1->add_dicvalue())->set_strvalue("e");
    tmp1->add_indexoffsets(0);
    tmp1->add_indexoffsets(2);
    tmp1->add_indexoffsets(4);
    tmp1->add_indexposting(10);
    tmp1->add_indexposting(11);
    tmp1->add_indexposting(12);
    tmp1->add_indexposting(13);
    tmp1->set_sliceno(2);
    tmp1->set_slicenum(2);
    MessagePtr msg1(tmp1);
    server.onUpdateGroupKeyData(conn , msg1 , time);
    sleep(3);
    EXPECT_EQ(1 , g_UpdateDataSendAck.taskid());
    EXPECT_EQ(SUCCESS , g_UpdateDataSendAck.statuscode());
    EXPECT_EQ("col1" , g_RawDataSendAck.columnname());
    EXPECT_EQ(2 , g_UpdateDataSendAck.dbid());
    EXPECT_EQ("test" , g_UpdateDataSendAck.tablename());
    EXPECT_EQ(0 , g_UpdateDataSendAck.xvector(0));
    EXPECT_EQ(1 , g_UpdateDataSendAck.xvector(1));
    EXPECT_EQ(1 , g_UpdateDataSendAck.xvector(2));

    ::INDEX_BORDER* border =  g_IndexSendMsg1.mutable_colindexborder();
    EXPECT_EQ(INDEX_BORDER_DICT_TYPE_VARCHAR , border->dicttype());
    EXPECT_EQ("e" , (border->mutable_dictupper())->strvalue());
    EXPECT_EQ("a" , (border->mutable_dictlower())->strvalue());
    EXPECT_EQ(4, border->entryupper());
    EXPECT_EQ(0, border->entrylower());
    g_ColumnTable->print();
}
