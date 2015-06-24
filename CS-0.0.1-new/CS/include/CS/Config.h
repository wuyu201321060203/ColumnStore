#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <vector>

#include <google/protobuf/message.h>

#include <boost/shared_ptr.hpp>

#include <protocol/common.pb.h>
#include <protocol/MSG_CS_CS_ENTRY_GET.pb.h>
#include <protocol/MSG_CS_CS_VALUE_GET.pb.h>
#include <protocol/MSG_CS_DC_COLUMN_POSITION_LOCATE.pb.h>
#include <protocol/MSG_CS_DC_LOCATION_INDEX_SEND.pb.h>
#include <protocol/MSG_CS_DC_RTABLE_POSITION_GET.pb.h>
#include <protocol/MSG_DC_CS_SYSTEM_STATUS_GET.pb.h>
#include <protocol/MSG_DS_CS_RAW_DATA_SEND.pb.h>
#include <protocol/MSG_DS_CS_RTABLE_CREATE.pb.h>
#include <protocol/MSG_DS_CS_RTABLE_SEND.pb.h>
#include <protocol/MSG_DS_CS_UPDATE_DATA_SEND.pb.h>
#include <protocol/MSG_PING_PONG.pb.h>
#include <protocol/MSG_CS_DC_MEMORY_INFO_SEND.pb.h>

#include <boost/weak_ptr.hpp>
#include <muduo/net/TcpConnection.h>

typedef unsigned int DB_ID_TYPE;
typedef boost::shared_ptr<google::protobuf::Message> MessagePtr;
typedef std::vector<uint64_t> Uint64Vec;
typedef boost::shared_ptr<std::vector<uint64_t> > Uint64VecPtr;
typedef std::string STDSTR;
typedef boost::shared_ptr<std::string> StdStrPtr;

#define ROLL_SIZE 4096
#define DEFAULT_THREADS 13

#define SHM_PATH "CSQE.shm"

#define RET_SUCCESS 0
#define RET_FAIL -1

#define INITIALORDER 0
#define PROTO_STRING 0
#define PROTO_INT 1
#define PROTO_DOUBLE 2
#define GROUPKEY_STRING 0
#define GROUPKEY_INT 1
#define GROUPKEY_DOUBLE 2

#define SUCCESS 0
#define NO_RTABLE_OF_THIS_TABLE -37
#define UNKNOWN_DICT_TYPE -38
#define EXISTED_RTABLE -39
#define UNEXISTED_DATABASE -40
#define UNEXISTED_TABLE -41
#define UNEXISTED_COL -42

#define MSG_DS_CS_RAW_DATA_SEND_CMD 0x1c
#define MSG_CS_DS_RAW_DATA_SEND_ACK_CMD 0x1d
#define MSG_DS_CS_RTABLE_CREATE_CMD 0x26
#define MSG_CS_DS_RTABLE_CREATE_ACK_CMD 0x27
#define MSG_DS_CS_UPDATE_DATA_SEND_CMD 0x28
#define MSG_CS_DS_UPDATE_DATA_SEND_ACK_CMD 0x29
#define MSG_DS_CS_RTABLE_SEND_CMD 0x2a
#define MSG_CS_DS_RTABLE_SEND_ACK_CMD 0x2b
#define MSG_DC_CS_SYSTEM_STATUS_GET_CMD 0x40

#define MSG_CS_DC_SYSTEM_STATUS_GET_ACK_CMD 0x41
#define MSG_CS_DC_LOCATION_INDEX_SEND_CMD 0x44
#define MSG_DC_CS_LOCATION_INDEX_SEND_ACK_CMD 0x45
#define MSG_CS_DC_MEMORY_INFO_SEND_CMD 0x42
#define MSG_DC_CS_MEMORY_INFO_SEND_ACK_CMD 0x43

#define MSG_QE_CS_REQUEST_COLUMN 0x50
#define MSG_CS_QE_REQUEST_COLUMN_ACK 0x51
#define MSG_QE_CS_DICTINDEX_VALUE 0x52
#define MSG_CS_QE_DICTINDEX_VALUE_ACK 0x53
#define MSG_QE_CS_ROWKEY_DICTINDEX 0x54
#define MSG_CS_QE_ROWKEY_DICTINDEX_ACK 0x55

enum class Choice
{
   choiceRead = 0,
   choiceWrite
};

typedef unsigned int UINT;

#define AVERAGE_ROW_NUM 1000

#define LIKELY(x) __builtin_expect(!!(x), 1)
#define UNLIKELY(x) __builtin_expect(!!(x), 0)

typedef MSG_CS_CS_ENTRY_GET EntryGetMsg;
typedef boost::shared_ptr<EntryGetMsg> EntryGetMsgPtr;

typedef MSG_CS_CS_ENTRY_GET_ACK EntryGetAck;
typedef boost::shared_ptr<EntryGetAck> EntryGetAckPtr;

typedef MSG_CS_CS_VALUE_GET ValueGetMsg;
typedef boost::shared_ptr<ValueGetMsg> ValueGetMsgPtr;

typedef MSG_CS_CS_VALUE_GET_ACK ValueGetAck;
typedef boost::shared_ptr<ValueGetAck> ValueGetAckPtr;

typedef MSG_CS_DC_COLUMN_POSITION_LOCATE ColumnLocateMsg;
typedef boost::shared_ptr<ColumnLocateMsg> ColumnLocateMsgPtr;

typedef MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK ColumnLocateAck;
typedef boost::shared_ptr<ColumnLocateAck> ColumnLocateAckPtr;

typedef MSG_CS_DC_LOCATION_INDEX_SEND IndexSendMsg;
typedef boost::shared_ptr<IndexSendMsg> IndexSendMsgPtr;

typedef MSG_DC_CS_LOCATION_INDEX_SEND_ACK IndexSendAck;
typedef boost::shared_ptr<IndexSendAck> IndexSendAckPtr;

typedef MSG_CS_DC_RTABLE_POSITION_GET RTablePosGetMsg;
typedef boost::shared_ptr<RTablePosGetMsg> RTablePosGetMsgPtr;

typedef MSG_DC_CS_RTABLE_POSITION_GET_ACK RTablePosGetAck;
typedef boost::shared_ptr<RTablePosGetAck> RTablePosGetAckPtr;

typedef MSG_DC_CS_SYSTEM_STATUS_GET SysStatGetMsg;
typedef boost::shared_ptr<SysStatGetMsg> SysStatGetMsgPtr;

typedef MSG_CS_DC_SYSTEM_STATUS_GET_ACK SysStatGetAck;
typedef boost::shared_ptr<SysStatGetAck> SysStatGetAckPtr;

typedef MSG_DS_CS_RAW_DATA_SEND RawDataSendMsg;
typedef boost::shared_ptr<RawDataSendMsg> RawDataSendMsgPtr;

typedef MSG_CS_DS_RAW_DATA_SEND_ACK RawDataSendAck;
typedef boost::shared_ptr<RawDataSendAck> RawDataSendAckPtr;

typedef MSG_DS_CS_RTABLE_CREATE RTableCreateMsg;
typedef boost::shared_ptr<RTableCreateMsg> RTableCreateMsgPtr;

typedef MSG_CS_DS_RTABLE_CREATE_ACK RTableCreateAck;
typedef boost::shared_ptr<RTableCreateAck> RTableCreateAckPtr;

typedef MSG_DS_CS_RTABLE_SEND RTableSendMsg;
typedef boost::shared_ptr<RTableSendMsg> RTableSendMsgPtr;

typedef MSG_CS_DS_RTABLE_SEND_ACK RTableSendAck;
typedef boost::shared_ptr<RTableSendAck> RTableSendAckPtr;

typedef MSG_DS_CS_UPDATE_DATA_SEND UpdateDataSendMsg;
typedef boost::shared_ptr<UpdateDataSendMsg> UpdateDataSendMsgPtr;

typedef MSG_CS_DS_UPDATE_DATA_SEND_ACK UpdateDataSendAck;
typedef boost::shared_ptr<UpdateDataSendAck> UpdateDataSendAckPtr;

typedef PING PingMsg;
typedef PONG PongMsg;

typedef MSG_CS_DC_MEMORY_INFO_SEND MemInfoSendMsg;
typedef boost::shared_ptr<MemInfoSendMsg> MemInfoSendMsgPtr;

typedef MSG_QE_CS_REQUEST_COLUMN ReqColByFilterMsg;
typedef boost::shared_ptr<ReqColByFilterMsg> ReqColByFilterMsgPtr;

typedef MSG_CS_QE_REQUEST_COLUMN_ACK ReqColByFilterAck;
typedef boost::shared_ptr<ReqColByFilterMsgAck> ReqColByFilterAckPtr;

typedef MSG_QE_CS_DICTINDEX_VALUE ReqColByDictIndexMsg;
typedef boost::shared_ptr<ReqColByDictIndexMsg> ReqColByDictIndexMsgPtr;

typedef MSG_CS_QE_DICTINDEX_VALUE_ACK ReqColByDictIndexAck;
typedef boost::shared_ptr<ReqColByDictIndexAck> ReqColByDictIndexAckPtr;

typedef MSG_QE_CS_ROWKEY_DICTINDEX ReqDictIndexMsg;
typedef boost::shared_ptr<ReqDictIndexMsg> ReqDictIndexMsgPtr;

typedef MSG_CS_QE_ROWKEY_DICTINDEX_ACK ReqDictIndexAck;
typedef boost::shared_ptr<ReqDictIndexAck> ReqDictIndexAckPtr;

#endif
