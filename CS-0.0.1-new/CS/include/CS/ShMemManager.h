#ifndef SHMEMMANAGER_H
#define SHMEMMANAGER_H

#include <string>

#include "Config.h"

class ShMemManager
{
public:

    ShMemManager(std::string filePath);
    ShMemManager(std::string filePath , std::string separator);
    int shMemOutput(std::string const& rowKey , UINT& length);
    int shMemOutput(std::string const& rowKey , std::string const& freq ,
                    std::string const& value , UINT& length);

private:

    char* createSharedMem(UINT size);
    int detachSharedMem(void* addr , size_t length);

private:

    std::string _filePath;
    std::string _separator;
};

#endif