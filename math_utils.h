#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#include <vector>
#include <numeric>

namespace simplecpp {

    template <typename T>
    T sum(const std::vector<T>& numbers);

    template <typename T>
    T average(const std::vector<T>& numbers);

}

#endif // MATH_UTILS_H
