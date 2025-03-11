// string_utils.h
#pragma once
#include <string>
#include <vector>

namespace simplecpp {
    std::string toUpper(const std::string& str);
    std::string toLower(const std::string& str);
    std::vector<std::string> split(const std::string& str, char delimiter);
}