#include <CS/Util.h>

using std::string;

StdStrPtr io::changeRetVal2Str(std::vector<int> const& input)
{
    UINT len = input.size() * sizeof(int);
    char inputStr[len + 1];
    inputStr[len] = '\0';
    memcpy(inputStr , input.data() , len);
    return StdStrPtr( new string(inputStr) );
}

StdStrPtr io::changeRetVal2Str(std::vector<uint64_t> const& input)
{
    UINT len = input.size() * sizeof(uint64_t);
    char inputStr[len + 1];
    inputStr[len] = '\0';
    memcpy(inputStr , input.data() , len);
    return StdStrPtr( new string(inputStr) );
}

StdStrPtr io::changeRetVal2Str(std::vector<std::string> const& input)
{
    string ret;
    fot(UINT i = 0 ; i != input.size() - 1 ; ++i)
        ret += (input[i] + "\t");
    ret += input[i];
    return StdStrPtr(new string(ret));
}

StdStrPtr io::changeRetVal2Str(std::vector<double> const& input)
{
    UINT len = input.size() * sizeof(double);
    char inputStr[len + 1];
    inputStr[len] = '\0';
    memcpy(inputStr , input.data() , len);
    return StdStrPtr( new string(inputStr) );
}

Uint64VecPtr io::parse(string const& input)
{
    UINT elementNum = input.size()/sizeof(uint64_t);
    Uint64VecPtr vec(new std::vector<uint64_t>);
    vec->reserve(elementNum);
    for(UINT i = 0 ; i != input.size() ;)
    {
        vec->push_back( boost::lexical_cast<uint64_t>(
            input.substr( i , sizeof(uint64_t) ) ) );
        i += sizeof(uint64_t);
    }
    return vec;
}