// file_utils.cpp
#include "file_utils.h"

bool simplecpp::writeToFile(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);
    if (!file) return false;
    file << content;
    return true;
}

std::string simplecpp::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) return "";
    return std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
}