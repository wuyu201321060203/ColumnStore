#include <CS/ProtobufLabCodec.h>
#include <CS/Config.h>
#include <CS/Initializer.h>
#include <muduo/net/TcpConnection.h>
#include <muduo/base/Timestamp.h>
#include <muduo/base/Logging.h>
#include <boost/bind.hpp>

#include <stdio.h>
#include <zlib.h>  // adler32

using namespace muduo;
using namespace muduo::net;

void print(const Buffer& buf)
{
    printf("encoded to %zd bytes\n", buf.readableBytes());
    for (size_t i = 0; i < buf.readableBytes(); ++i)
    {
        unsigned char ch = static_cast<unsigned char>(buf.peek()[i]);

        printf("%2zd:  0x%02x  %c\n", i, ch, isgraph(ch) ? ch : ' ');
    }
}

void foo(TcpConnectionPtr const& conn , MessagePtr const& msg , Timestamp time)
{

}

void test()
{
    ProtobufLabCodec::registeLabMsg(MSG_DS_CS_RTABLE_CREATE_CMD,
        "MSG_DS_CS_RTABLE_CREATE");

    RTableCreateMsg msg;
    msg.set_taskid(2);
    msg.set_dbid(4);
    Buffer buf;
    ProtobufLabCodec::fillEmptyBuffer(&buf, msg);
    print(buf);
    TcpConnectionPtr conn;
    InetAddress localAddr(10);
    InetAddress remoteAddr(100);
    int socketfd = ::socket(AF_INET , SOCK_STREAM , IPPROTO_TCP);
    conn.reset( new TcpConnection(&Initializer::getEventLoop(),
        "conn" , socketfd , localAddr , remoteAddr) );
    ProtobufLabCodec codec(boost::bind(&foo , _1 , _2 , _3));
    Timestamp time;
    codec.onMessage(conn , &buf , time);
}

int main()
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    test();
    google::protobuf::ShutdownProtobufLibrary();
    return 0;
}

