#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>

namespace simplecpp {

    bool writeToFile(const std::string& filename, const std::string& content);
    std::string readFromFile(const std::string& filename);
    bool createDirectory(const std::string& directory);

}

#endif // FILE_UTILS_H
