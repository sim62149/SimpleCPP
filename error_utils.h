#ifndef ERROR_UTILS_H
#define ERROR_UTILS_H

#include <stdexcept>
#include <string>

namespace simplecpp {

    class SimpleCPPError : public std::runtime_error {
    public:
        explicit SimpleCPPError(const std::string& message) : std::runtime_error(message) {}
    };

    void handleError(const std::string& message);
}

#endif // ERROR_UTILS_H
