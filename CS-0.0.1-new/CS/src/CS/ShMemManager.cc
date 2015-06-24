#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <cstring>
#include <errno.h>

#include <muduo/base/Logging.h>

#include <CS/ShMemManager.h>

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
#define SEPARATOR_LENGTH 2
#define SEPARATOR_NUM 2

using std::string;

ShMemManager::ShMemManager(string filePath):_filePath(filePath) , _separator("\r\n")
{}

ShMemManager::ShMemManager(string filePath , string separator):
                                                            _filePath(filePath),
                                                            _separator(separator)
{}

int ShMemManager::shMemOutput(string const& rowKey , UINT& length)
{
    length = rowKey.size();
    char* ptr = createSharedMem(length);
    if(ptr != NULL)
    {
        memcpy(ptr , rowKey.c_str() , length);
        detachSharedMem( ptr , rowKey.size() );
        return RET_SUCCESS;
    }
    else
        return RET_FAIL;
}

int ShMemManager::shMemOutput(string const& rowKey , string const& freq,
                              string const& value , UINT& length)
{
    int rSize = rowKey.size();
    int fSize = freq.size();
    int vSize = value.size();
    length = rSize + fSize + vSize + SEPARATOR_NUM * SEPARATOR_LENGTH;
    char* ptr = createSharedMem(length);
    if(ptr != NULL)
    {
        char* copyAddr = ptr;
        int lastSize = 0;
        memcpy( copyAddr , ( rowKey + _separator ).c_str(),
            (lastSize = rSize + SEPARATOR_LENGTH) );
        copyAddr += lastSize;
        memcpy( copyAddr , ( freq + _separator ).c_str(),
            (lastSize = freq.size() + SEPARATOR_LENGTH) );
        memcpy(copyAddr + lastSize , value.c_str() , vSize);
        detachSharedMem(ptr , length);
        return RET_SUCCESS;
    }
    else
        return RET_FAIL;
}

char* ShMemManager::createSharedMem(UINT size)
{
    shm_unlink( _filePath.c_str() );
    int fd = shm_open( _filePath.c_str() , O_RDWR | O_CREAT | O_EXCL , FILE_MODE);
    char* ptr = NULL;
    if(0 < fd)
    {
        ptr = static_cast<char*>( mmap(NULL , size , PROT_READ | PROT_WRITE,
            MAP_SHARED , fd , 0) );
        ftruncate(fd , size);
        close(fd);
    }
    else if(0 > fd && errno == EEXIST)
        LOG_ERROR << "QE does not unlink shared memory";
    else
        LOG_ERROR << "can't open a shared object for QE";
    return ptr;
}

int ShMemManager::detachSharedMem(void* addr , size_t length)
{
    munmap(addr , length);
}