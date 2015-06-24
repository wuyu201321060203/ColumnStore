#include <CS/BaseOperator.h>

using std::string;

int BaseOperator::query(int base , DGroupKey<int> const& column,
                        string& rowKey , string& freq , string& value)
{
}

int BaseOperator::query(string base , DGroupKey<string> const& column,
                        string& rowKey , string& freq , string& value)
{
}

int BaseOperator::query(double base , DGroupKey<double> const& column,
                        string& rowKey , string& freq , string& value)
{
}

int BaseOperator::query(int base , DGroupKey<int> const& column,
                        string& rowKey)
{
}

int BaseOperator::query(string base , DGroupKey<string> const& column,
                        string& rowKey)
{
}

int BaseOperator::query(double base , DGroupKey<double> const& column,
                        string& rowKey)
{
}