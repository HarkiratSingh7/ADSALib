#ifndef FRAMEWORK_H
#define FRAMEWORK_H
#include <functional>
#include <cstddef>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

typedef unsigned int uint32;

namespace algolib
{
    static std::ostream *algolib_log_out = nullptr;

    void SetLog_OSTREAM_OBJ(std::ostream *log)
    {
        algolib_log_out = log;
    }
} // namespace algolib

#define _LOG_(x)                    \
    if (algolib_log_out != nullptr) \
    *algolib_log_out << x << '\n'

#endif