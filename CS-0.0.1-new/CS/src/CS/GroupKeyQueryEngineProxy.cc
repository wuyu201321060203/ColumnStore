#include <CS/GroupKeyQueryEngineProxy.h>

GroupKeyQueryEngineProxy::GroupKeyQueryEngineProxy():_opPool(new OperatorPool)
{

}

int GroupKeyQueryEngineProxy::executeQuery(uint32_t cmd , int base,
                                           DGroupKey<int> const& column,
                                           string& rowKey , string& freq,
                                           string& value)
{
    _opPool->getOperator(cmd)->query(base , column , rowKey , freq , value);
}

int GroupKeyQueryEngineProxy::executeQuery(uint32_t cmd , string base,
                                           DGroupKey<string> const& column,
                                           string& rowKey , string& freq,
                                           string& value)
{
    _opPool->getOperator(cmd)->query(base , column , rowKey , freq , value);
}

int GroupKeyQueryEngineProxy::executeQuery(uint32_t cmd , double base,
                                           DGroupKey<double> const& column,
                                           string& rowKey , string& freq,
                                           string& value)
{
    _opPool->getOperator(cmd)->query(base , column , rowKey , freq , value);
}

int GroupKeyQueryEngineProxy::executeQuery(uint32_t cmd , int base,
                                           DGroupKey<int> const& column,
                                           string& rowKey)
{
    _opPool->getOperator(cmd)->query(base , column , rowKey);
}

int GroupKeyQueryEngineProxy::executeQuery(uint32_t cmd , string base,
                                           DGroupKey<string> const& column,
                                           string& rowKey)
{
    _opPool->getOperator(cmd)->query(base , column , rowKey);
}

int GroupKeyQueryEngineProxy::executeQuery(uint32_t cmd , double base,
                                           DGroupKey<double> const& column,
                                           string& rowKey)
{
    _opPool->getOperator(cmd)->query(base , column , rowKey);
}