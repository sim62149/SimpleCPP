// array_utils.h
#pragma once
#include <vector>
#include <string>
#include <functional>

namespace simplecpp {
    std::string join(const std::vector<std::string>& elements, const std::string& delimiter);
    std::vector<int> map(const std::vector<int>& elements, std::function<int(int)> func);
    std::vector<int> filter(const std::vector<int>& elements, std::function<bool(int)> func);
}
