#ifndef GTOPERATOR_H
#define GTOPERATOR_H

#include "BaseOperator.h"

class GTOperator : public BaseOperator
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
        int64_t ret = column.getDictionary()->gtGetPos(base);
        if(ret >= 0)
        {
            Uint64Vec rowKeyVec;
            Uint64Vec freqVec;
            std::vector<T> valueVec;
            int retValue =  column.getRangeThreeVecByPos(static_cast<uint64_t>(ret),
                                            ( column.getDictionary() )->getRows(),
                                             rowKeyVec , freqVec , valueVec);
            if(retValue == RET_SUCCESS)
            {
                rowKey = *( io::changeRetVal2Str(rowKeyVec) );
                freq = *( io::changeRetVal2Str(freqVec) );
                value = *( io::changeRetVal2Str(valueVec) );
            }
            return retValue;
        }
        else
            return RET_FAIL;
    }

    template<typename T>
    int queryImpl(T base , DGroupKey<T> const& column , std::string& rowKey)
    {
        int64_t ret = column.getDictionary()->gtGetPos(base);
        if(ret >= 0)
        {
            Uint64Vec rowKeyVec;
            int retValue =  column.getRangeRowKeyByPos(static_cast<uint64_t>(ret),
                ( column.getDictionary() )->getRows() , rowKeyVec);

            if(retValue == RET_SUCCESS)
                rowKey = *( io::changeRetVal2Str(rowKeyVec) );
            return retValue;
        }
        else
            return RET_FAIL;
    }
};

#endif