#ifndef MEMORY_UTILS_H
#define MEMORY_UTILS_H

#include <memory>

namespace simplecpp {

    template <typename T>
    using Ptr = std::unique_ptr<T>;

    template <typename T>
    Ptr<T> makePtr(T* ptr) {
        return Ptr<T>(ptr);
    }

    template <typename T>
    Ptr<T> makePtr(T&& obj) {
        return Ptr<T>(new T(std::forward<T>(obj)));
    }

}

#endif // MEMORY_UTILS_H
