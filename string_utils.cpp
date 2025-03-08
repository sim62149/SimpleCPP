#include "string_utils.h"
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

namespace simplecpp {

    std::string toUpper(const std::string& str) {
        std::string result = str;
        std::transform(result.begin(), result.end(), result.begin(), ::toupper);
        return result;
    }

    std::string toLower(const std::string& str) {
        std::string result = str;
        std::transform(result.begin(), result.end(), result.begin(), ::tolower);
        return result;
    }

    std::string trim(const std::string& str) {
        const auto first = str.find_first_not_of(' ');
        const auto last = str.find_last_not_of(' ');
        return str.substr(first, (last - first + 1));
    }

    // Refactorée sans va_start
    std::string format(const std::string& fmt, const std::vector<std::string>& args) {
        std::stringstream formatted;
        size_t pos = 0;
        size_t argIndex = 0;

        // Remplacer chaque occurrence de {} dans fmt par les éléments de args
        while ((pos = fmt.find("{}", pos)) != std::string::npos && argIndex < args.size()) {
            formatted << fmt.substr(0, pos) << args[argIndex++];
            pos += 2;  // Longueur de "{}"
        }

        // Ajouter le reste de la chaîne formatée
        formatted << fmt.substr(pos);
        return formatted.str();
    }

}

