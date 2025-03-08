#include "math_utils.h"

namespace simplecpp {

    template <typename T>
    T sum(const std::vector<T>& numbers) {
        return std::accumulate(numbers.begin(), numbers.end(), T(0));
    }

    template <typename T>
    T average(const std::vector<T>& numbers) {
        if (numbers.empty()) return T(0);
        return sum(numbers) / static_cast<T>(numbers.size());
    }

}
