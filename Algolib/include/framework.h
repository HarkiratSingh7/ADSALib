#ifndef FRAMEWORK_H
#define FRAMEWORK_H
#include <functional>
#include <cstddef>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iomanip>

typedef unsigned int uint32;

#define RUN_CALC_TIME(precedeText,func) {\
    cout << "\n"<<precedeText<<"\n";\
    auto timePoint1 = chrono::high_resolution_clock::now();\
    func;\
    auto timePoint2 = chrono::high_resolution_clock::now();\
    double TIME_TAKEN = chrono::duration_cast<chrono::nanoseconds>(timePoint2 - timePoint1).count();\
    TIME_TAKEN *= 1e-9;\
    cout <<'\n'<<"Time: "<<fixed << TIME_TAKEN<<setprecision(9) << " s time elapsed" << endl;\
}

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