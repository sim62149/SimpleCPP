// file_utils.h
#pragma once
#include <string>
#include <fstream>

namespace simplecpp {
    bool writeToFile(const std::string& filename, const std::string& content);
    std::string readFromFile(const std::string& filename);
}