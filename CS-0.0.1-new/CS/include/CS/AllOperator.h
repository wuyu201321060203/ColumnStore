#ifndef ALLOPERATOR_H
#define ALLOPERATOR_H

#include "BaseOperator.h"

class ALLOperator : public BaseOperator
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
        column.getAllThreeVec(rowkeyVec , freqVec , valueVec);
        rowKey = *( io::changeRetVal2Str(rowkeyVec) );
        freq = *( io::changeRetVal2Str(freqVec) );
        value = *( io::changeRetVal2Str(valueVec) );
        return RET_SUCCESS;
    }

    template<typename T>
    int queryImpl(T base , DGroupKey<T> const& column , std::string& rowKey)
    {
        Uint64Vec rowkeyVec;
        column.getAllRowKey(rowkeyVec);
        rowKey = *( io::changeRetVal2Str(rowkeyVec) );
        return RET_SUCCESS;
    }
};

#endif