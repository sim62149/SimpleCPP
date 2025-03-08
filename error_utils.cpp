// error_utils.cpp
#include "error_utils.h"

void simplecpp::handleError(const std::string& message) {
    std::cerr << "[ERROR] " << message << std::endl;
}