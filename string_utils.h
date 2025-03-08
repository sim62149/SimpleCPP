#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <string>
#include <algorithm>

namespace simplecpp {

    std::string toUpper(const std::string& str);
    std::string toLower(const std::string& str);
    std::string trim(const std::string& str);
    std::string format(const std::string& fmt, ...);

}

#endif // STRING_UTILS_H
