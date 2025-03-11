// file_utils.h
#pragma once
#include <string>
#include <vector>

namespace simplecpp {
    bool writeToFile(const std::string& filename, const std::string& content);
    bool appendToFile(const std::string& filename, const std::string& content);
    std::string readFromFile(const std::string& filename);
    bool deleteFile(const std::string& filename);
    bool fileExists(const std::string& filename);
    std::vector<std::string> readLinesFromFile(const std::string& filename);
    bool writeLinesToFile(const std::string& filename, const std::vector<std::string>& lines);
}
