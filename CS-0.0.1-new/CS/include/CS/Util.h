#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <vector>

#include "Config.h"

namespace io
{
    StdStrPtr changeRetVal2Str(std::vector<int> const& input);
    StdStrPtr changeRetVal2Str(std::vector<uint64_t> const& input);
    StdStrPtr changeRetVal2Str(std::vector<std::string> const& input);
    StdStrPtr changeRetVal2Str(std::vector<double> const& input);
    Uint64VecPtr parse(string const& input);
}

#endif