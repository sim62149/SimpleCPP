// math_utils.cpp
#include "math_utils.h"

int simplecpp::sum(const std::vector<int>& numbers) {
    int total = 0;
    for (int n : numbers) total += n;
    return total;
}

double simplecpp::average(const std::vector<int>& numbers) {
    if (numbers.empty()) return 0;
    return (double)simplecpp::sum(numbers) / numbers.size();
}