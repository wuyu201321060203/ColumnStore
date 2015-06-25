#ifndef TOPOPERATOR_H
#define TOPOPERATOR_H

#include <string>
#include <vector>

#include <boost/lexical_cast.hpp>

#include "DGroupKey.h"
#include "BaseOperator.h"

class TopOperator : public BaseOperator
{
public:

    int query(int base , DGroupKey<int> const& column , std::string& rowKey,
              std::string& freq , std::string& value)
    {
        return queryImpl(base , column , rowKey , freq , value);
    }

    int query(std::string base , DGroupKey<std::string> const& column , std::string& rowKey,
              std::string& freq , std::string& value)
    {
        double tmp = boost::lexical_cast<double>(base);
        return queryImpl(tmp , column , rowKey , freq , value);
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

    int query(std::string base , DGroupKey<std::string> const& column , std::string& rowKey)
    {
        double tmp = boost::lexical_cast<double>(base);
        return queryImpl(tmp , column , rowKey);
    }

    int query(double base , DGroupKey<double> const&  column , std::string& rowKey)
    {
        return queryImpl(base , column , rowKey);
    }

private:

    template<typename T>
    int queryImpl(double base , DGroupKey<T> const& column , std::string& rowKey,
                  std::string& freq , std::string& value)
    {
        Uint64Vec rowKeyVec;
        Uint64Vec freqVec;
        std::vector<T> valueVec;
        int ret =  column.getRangeThreeVecByPos(0 , base , rowKeyVec , freqVec,
                                                    valueVec);
        if(ret == RET_SUCCESS)
        {
            rowKey = *( io::changeRetVal2Str(rowKeyVec) );
            freq = *( io::changeRetVal2Str(freqVec) );
            value = *( io::changeRetVal2Str(valueVec) );
        }
        return ret;
    }

    template<typename T>
    int queryImpl(double base , DGroupKey<T> const& column , std::string& rowKey)
    {
        Uint64Vec rowKeyVec;
        int ret =  column.getRangeRowKeyByPos(0 , base , rowKeyVec);
        if(ret == RET_SUCCESS)
            rowKey = *( io::changeRetVal2Str(rowKeyVec) );
        return ret;
    }
};

#endif