#ifndef OPERATORPOOL_H
#define OPERATORPOOL_H

#include <vector>

#include "BaseOperator.h"

class OperatorPool
{
public:

    OperatorPool();
    typedef std::vector<BaseOperatorPtr> OperatorVec;
    BaseOperatorPtr getOperator(uint32_t cmd);

private:

    OperatorVec _opVec;
};

#endif