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