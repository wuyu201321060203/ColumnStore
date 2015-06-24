#include <CS/GroupKeyQueryEngineProxy.h>

GroupKeyQueryEngineProxy::GroupKeyQueryEngineProxy():_opPool(new OperatorPool)
{

}

int GroupKeyQueryEngineProxy::executeQuery(uint32_t cmd , int base,
                                           DGroupKey<int> const& column,
                                           string& rowKey , string& freq,
                                           strint& value)
{
    _opPool->getOperator(cmd)->query(base , column , rowKey , freq , value);
}

int GroupKeyQueryEngineProxy::executeQuery(uint32_t cmd , string base,
                                           DGroupKey<string> const& column,
                                           string& rowKey , string& freq,
                                           strint& value)
{
    _opPool->getOperator(cmd)->query(base , column , rowKey , freq , value);
}

int GroupKeyQueryEngineProxy::executeQuery(uint32_t cmd , double base,
                                           DGroupKey<double> const& column,
                                           string& rowKey , string& freq,
                                           strint& value)
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

/*
int GroupKeyQueryEngineProxy::executeQuery(Uint64Vec const& posList,
                                           DGroupKey<int> const& column,
                                           string& rowKey , string& freq,
                                           strint& value)
{
    Uint64Vec rowkeyVec;
    Uint64Vec freqVec;
    std::vector<int> valueVec;
    int ret = column.getThreeVecByPosList(posList , rowkeyVec , freqVec , valueVec);
    if(ret == RET_SUCCESS)
    {
        rowkey = *( io::changeRetVal2Str(rowkeyVec) );
        freq = *( io::changeRetVal2Str(freqVec) );
        value = *( io::changeRetVal2Str(valueVec) );
    }
    return ret;
}

int GroupKeyQueryEngineProxy::executeQuery(Uint64Vec const& posList,
                                           DGroupKey<string> const& column,
                                           string& rowKey , string& freq,
                                           strint& value)
{
    Uint64Vec rowkeyVec;
    Uint64Vec freqVec;
    std::vector<string> valueVec;
    int ret = column.getThreeVecByPosList(posList , rowkeyVec , freqVec , valueVec);
    if(ret == RET_SUCCESS)
    {
        rowkey = *( io::changeRetVal2Str(rowkeyVec) );
        freq = *( io::changeRetVal2Str(freqVec) );
        value = *( io::changeRetVal2Str(valueVec) );
    }
    return ret;
}

int GroupKeyQueryEngineProxy::executeQuery(Uint64Vec const& posList,
                                           DGroupKey<double> const& column,
                                           string& rowKey , string& freq,
                                           strint& value)
{
    Uint64Vec rowkeyVec;
    Uint64Vec freqVec;
    std::vector<double> valueVec;
    int ret = column.getThreeVecByPosList(posList , rowkeyVec , freqVec , valueVec);
    if(ret == RET_SUCCESS)
    {
        rowkey = *( io::changeRetVal2Str(rowkeyVec) );
        freq = *( io::changeRetVal2Str(freqVec) );
        value = *( io::changeRetVal2Str(valueVec) );
    }
    return ret;
}

int GroupKeyQueryEngineProxy::executeQuery(Uint64Vec const& posList,
                                           DGroupKey<int> const& column,
                                           string& rowKey)
{
    Uint64Vec rowkeyVec;
    int ret = column.getRowKeyByPosList(posList , rowkeyVec);
    if(ret == RET_SUCCESS)
        rowKey = *( io::changeRetVal2Str(rowkeyVec) );
    return ret;
}

int GroupKeyQueryEngineProxy::executeQuery(Uint64Vec const& posList,
                                           DGroupKey<string> const& column,
                                           string& rowKey)
{
    Uint64Vec rowkeyVec;
    int ret = column.getRowKeyByPosList(posList , rowkeyVec);
    if(ret == RET_SUCCESS)
        rowKey = *( io::changeRetVal2Str(rowkeyVec) );
    return ret;
}

int GroupKeyQueryEngineProxy::executeQuery(Uint64Vec const& posList,
                                           DGroupKey<double> const& column,
                                           string& rowKey)
{
    Uint64Vec rowkeyVec;
    int ret = column.getRowKeyByPosList(posList , rowkeyVec);
    if(ret == RET_SUCCESS)
        rowKey = *( io::changeRetVal2Str(rowkeyVec) );
    return ret;
}
*/