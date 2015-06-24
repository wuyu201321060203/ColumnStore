#include <CS/OperatorPool.h>
#include <CS/AllOperator.h>
#include <CS/GTOperator.h>
#include <CS/GEOperator.h>
#include <CS/LTOperator.h>
#include <CS/LEOperator.h>
#include <CS/EQOperator.h>
#include <CS/NEOperator.h>
#include <CS/TopOperator.h>

#define OPERATOR_NUM 8

OperatorPool::OperatorPool()
{
    BaseOperatorPtr allOperator(new AllOperator);
    BaseOperatorPtr gtOperator(new GTOperator);
    BaseOperatorPtr geOperator(new GEOperator);
    BaseOperatorPtr ltOperator(new LTOperator);
    BaseOperatorPtr leOperator(new LEOperator);
    BaseOperatorPtr eqOperator(new EQOperator);
    BaseOperatorPtr neOperator(new NEOperator);
    BaseOperatorPtr topOperator(new TopOperator);
    _opVec.reserve(OPERATOR_NUM);
    _opVec.push_back(allOperator);
    _opVec.push_back(gtOperator);
    _opVec.push_back(geOperator);
    _opVec.push_back(ltOperator);
    _opVec.push_back(leOperator);
    _opVec.push_back(eqOperator);
    _opVec.push_back(neOperator);
    _opVec.push_back(topOperator);
}

BaseOperatorPtr OperatorPool::getOperator(uint32_t cmd)
{
    return _opVec[cmd];
}