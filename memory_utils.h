// memory_utils.h
#pragma once

namespace simplecpp {
    template<typename T>
    T* safeNew() {
        try {
            return new T;
        }
        catch (const std::bad_alloc&) {
            handleError("Allocation m�moire �chou�e");
            return nullptr;
        }
    }
}