#ifndef GROUPKEYQUERYENGINEPROXY_H
#define GROUPKEYQUERYENGINEPROXY_H

#include <boost/shared_ptr.hpp>

#include "DGroupKey.h"
#include "OperatorPool.h"
#include "Config.h"

using std::string;

class GroupKeyQueryEngineProxy
{
public:

    GroupKeyQueryEngineProxy();

    int executeQuery(uint32_t cmd , int base , DGroupKey<int> const& column,
                     string& rowKey , string& freq , string& value);
    int executeQuery(uint32_t cmd , string base , DGroupKey<string> const& column,
                     string& rowKey , string& freq , string& value);
    int executeQuery(uint32_t cmd , double base , DGroupKey<double> const& column,
                     string& rowKey , string& freq , string& value);

    int executeQuery(uint32_t cmd , int base , DGroupKey<int> const& column,
                     string& rowKey);
    int executeQuery(uint32_t cmd , string base , DGroupKey<string> const& column,
                     string& rowKey);
    int executeQuery(uint32_t cmd , double base , DGroupKey<double> const& column,
                     string& rowKey);

    template<typename T>
    int executeQuery(Uint64Vec const& posList , DGroupKey<T> const& column,
                     string& rowKey , string& freq , string& value)
    {
        Uint64Vec rowkeyVec;
        Uint64Vec freqVec;
        std::vector<T> valueVec;
        int ret = column.getThreeVecByPos(posList , rowkeyVec , freqVec , valueVec);
        if(ret == RET_SUCCESS)
        {
            rowKey = *( io::changeRetVal2Str(rowkeyVec) );
            freq = *( io::changeRetVal2Str(freqVec) );
            value = *( io::changeRetVal2Str(valueVec) );
        }
        return ret;
    }

    template<typename T>
    int executeQuery(Uint64Vec const& posList , DGroupKey<T> const& column,
                     string& rowKey)
    {
        Uint64Vec rowkeyVec;
        int ret = column.getRowKeyByPos(posList , rowkeyVec);
        if(ret == RET_SUCCESS)
            rowKey = *( io::changeRetVal2Str(rowkeyVec) );
        return ret;
    }

private:

    OperatorPoolPtr _opPool;
};

typedef boost::shared_ptr<GroupKeyQueryEngineProxy> GroupKeyQueryEngineProxyPtr;

#endif