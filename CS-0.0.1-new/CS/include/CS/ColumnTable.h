#ifndef COLUMNTABLE_H
#define COLUMNTABLE_H

#include <string>

#include "DGroupKey.h"
#include "RWMutex.h"

using namespace std;

class ColumnTable
{
private:

    typedef vector<pair<string, size_t> > vector_t;

public:

    ColumnTable(string tableName);
    virtual ~ColumnTable();
    void insertOneDGroupKey(void* insertPtr, string columnName, size_t type);
    pair<void*, size_t> getOneDGroupKey(string columnName);
    vector<uint64_t> updateOneDGroupKey(void* updatePtr, string columnName, size_t type);
    string getTableName();
    void print();

    inline size_t getPos(string columnName)//precise search, if not exist, return -1
    {
        for(vector_t::iterator itr = m_indexVector.begin(); itr != m_indexVector.end();
            itr++)
        {
            if((*itr).first == columnName)
                return distance(m_indexVector.begin(), itr);
        }
        return -1;
    }

private:

    string m_tableName;
    vector<void*> m_columns;
    vector_t m_indexVector;
    RWMutexLock _mutex;
};

#endif
