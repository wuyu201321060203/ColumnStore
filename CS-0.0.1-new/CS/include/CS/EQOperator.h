#ifndef EQOPERATOR_H
#define EQOPERATOR_H

#include "BaseOperator.h"

class EQOperator : public BaseOperator
{
public:

    int query(int base , DGroupKey<int> const& column , std::string& rowKey,
              std::string& freq , std::string& value)
    {
        return queryImpl(base , column , rowKey , freq , value);
    }

    int query(std::string base , DGroupKey<std::string> const& column,
              std::string& rowKey , std::string& freq , std::string& value)
    {
        return queryImpl(base , column , rowKey , freq , value);
    }

    int query(double base , DGroupKey<double> const& column , std::string& rowKey,
              std::string& freq , std::string& value)
    {
        return queryImpl(base , column , rowKey , freq , value);
    }

    int query(int base , DGroupKey<int> const& column , std::string& rowKey)
    {
        return queryImpl(base , column , rowKey);
    }

    int query(std::string base , DGroupKey<std::string> const& column,
              std::string& rowKey)
    {
        return queryImpl(base , column , rowKey);
    }

    int query(double base , DGroupKey<double> const&  column , std::string& rowKey)
    {
        return queryImpl(base , column , rowKey);
    }

private:

    template<typename T>
    int queryImpl(T base , DGroupKey<T> const& column , std::string& rowKey,
                  std::string& freq , std::string& value)
    {
        Uint64Vec rowkeyVec;
        Uint64Vec freqVec;
        std::vector<T> valueVec;
        int64_t ret = ( column.getDictionary() )->getSurePos(base);
        if(ret >= 0)
        {
            Uint64Vec posList(1 , static_cast<uint64_t>(ret) );
            column.getThreeVecByPos(posList , rowkeyVec , freqVec , valueVec);
            rowKey = *( io::changeRetVal2Str(rowkeyVec) );
            freq = *( io::changeRetVal2Str(freqVec) );
            value = *( io::changeRetVal2Str(valueVec) );
            return RET_SUCCESS;
        }
        else
            return RET_FAIL;
    }

    template<typename T>
    int queryImpl(T base , DGroupKey<T> const& column , std::string& rowKey)
    {
        Uint64Vec rowkeyVec;
        int64_t ret = ( column.getDictionary() )->getSurePos(base);
        if(ret >= 0)
        {
            Uint64Vec posList(1 , static_cast<uint64_t>(ret) );
            column.getRowKeyByPos(posList , rowkeyVec);
            rowKey = *( io::changeRetVal2Str(rowkeyVec) );
            return RET_SUCCESS;
        }
        else
            return RET_FAIL;
    }
};

#endif