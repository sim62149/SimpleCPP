#include "error_utils.h"

namespace simplecpp {

    void handleError(const std::string& message) {
        throw SimpleCPPError(message);
    }

}
