#include <CS/BaseOperator.h>

using std::string;

int BaseOperator::query(int base , DGroupKey<int> const& column,
                        string& rowKey , string& freq , string& value)
{
    return RET_SUCCESS;
}

int BaseOperator::query(string base , DGroupKey<string> const& column,
                        string& rowKey , string& freq , string& value)
{
    return RET_SUCCESS;
}

int BaseOperator::query(double base , DGroupKey<double> const& column,
                        string& rowKey , string& freq , string& value)
{
    return RET_SUCCESS;
}

int BaseOperator::query(int base , DGroupKey<int> const& column,
                        string& rowKey)
{
    return RET_SUCCESS;
}

int BaseOperator::query(string base , DGroupKey<string> const& column,
                        string& rowKey)
{
    return RET_SUCCESS;
}

int BaseOperator::query(double base , DGroupKey<double> const& column,
                        string& rowKey)
{
    return RET_SUCCESS;
}