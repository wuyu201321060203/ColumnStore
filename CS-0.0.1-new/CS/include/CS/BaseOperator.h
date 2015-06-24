#ifndef BASEOPERATOR_H
#define BASEOPERATOR_H

#include <boost/shared_ptr.hpp>

#include "Config.h"
#include "DGroupKey.h"

class BaseOperator
{
public:

    virtual int query(int base , DGroupKey<int> const& column,
                      std::string& rowKey , std::string& freq,
                      std::string& value) = 0;
    virtual int query(std::string base , DGroupKey<std::string> const& column,
                      std::string& rowKey , std::string& freq,
                      std::string& value) = 0;
    virtual int query(double base , DGroupKey<double> const& column,
                      std::string& rowKey , std::string& freq,
                      std::string& value) = 0;
    virtual int query(int base , DGroupKey<int> const& column,
                      std::string& rowKey) = 0;
    virtual int query(std::string base , DGroupKey<std::string> const& column,
                      std::string& rowKey) = 0;
    virtual int query(double base , DGroupKey<double> const& column,
                      std::string& rowKey) = 0;
};

typedef boost::shared_ptr<BaseOperator> BaseOperatorPtr;

#endif