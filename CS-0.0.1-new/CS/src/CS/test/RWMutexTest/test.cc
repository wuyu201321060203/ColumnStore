#include <CS/RWMutex.h>
#include <CS/Config.h>
#include <iostream>

using namespace std;

//创建一个读写锁对象
RWMutexLock g_myRWLock;
volatile int g_counter = 0;

//线程函数
void * StartThread(void *pParam)
{
    int lastCount = 0;
    for (int i = 0; i < 10000; ++i)
    {
        {
            RWMutexLockGuard tmpLock(g_myRWLock , Choice::choiceRead);
            //g_myRWLock.rdLock();
            lastCount = g_counter;
            //在读锁域，两个线程不断循环交替访问全局变量g_counter
            for (int k = 0; k < 100; ++k)
            {
                if (g_counter != lastCount)
                    cout<<"the value of g_counter has been updated."<<endl;
                sleep(0);
            }
        }
        //g_myRWLock.unlock();
        {
            RWMutexLockGuard tmpLock1(g_myRWLock , Choice::choiceWrite);
            //g_myRWLock.wrLock();
            //在写锁域，只有一个线程可以修改全局变量g_counter的值
            for (int k = 0; k < 100; ++k)
            {
                --g_counter;
                sleep(0);
            }
            for (int k = 0; k < 100; ++k)
            {
                ++g_counter;
                sleep(0);
            }
            ++g_counter;
            if (g_counter <= lastCount)
                cout<<"the value of g_counter is error."<<endl;
            //         g_myRWLock.unlock();
        }
    }
    return (void *)0;
}

int main(int argc, char* argv[])
{
    pthread_t thread1,thread2;
    pthread_attr_t attr1,attr2;

    //创建两个工作线程
    pthread_attr_init(&attr1);
    pthread_attr_setdetachstate(&attr1,PTHREAD_CREATE_JOINABLE);
    if (pthread_create(&thread1,&attr1, StartThread,0) == -1)
    {
        cout<<"Thread 1: create failed"<<endl;
    }
    pthread_attr_init(&attr2);
    pthread_attr_setdetachstate(&attr2,PTHREAD_CREATE_JOINABLE);
    if (pthread_create(&thread2,&attr2, StartThread,0) == -1)
    {
        cout<<"Thread 2: create failed"<<endl;
    }

    //等待线程结束
    void *result;
    pthread_join(thread1,&result);
    pthread_join(thread2,&result);

    //关闭线程，释放资源
    pthread_attr_destroy(&attr1);
    pthread_attr_destroy(&attr2);

    cout<<"the g_counter = "<<g_counter<<endl;

    int iWait;
    cin>>iWait;

    return 0;
}