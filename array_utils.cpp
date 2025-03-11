// array_utils.cpp
#include "array_utils.h"

std::string simplecpp::join(const std::vector<std::string>& elements, const std::string& delimiter) {
    std::string result;
    for (size_t i = 0; i < elements.size(); ++i) {
        result += elements[i];
        if (i < elements.size() - 1) {
            result += delimiter;
        }
    }
    return result;
}

std::vector<int> simplecpp::map(const std::vector<int>& elements, std::function<int(int)> func) {
    std::vector<int> result;
    for (int val : elements) {
        result.push_back(func(val));
    }
    return result;
}

std::vector<int> simplecpp::filter(const std::vector<int>& elements, std::function<bool(int)> func) {
    std::vector<int> result;
    for (int val : elements) {
        if (func(val)) {
            result.push_back(val);
        }
    }
    return result;
}