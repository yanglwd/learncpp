#pragma once

#include <mutex>

#include "nocopy.h"

namespace Utility {

template <typename T>
class Singleton : public NoCopy {
  public:
    Singleton() = default;
    ~Singleton() = default;

    T& Instance();
    // void Destroy();

  private:
    static T* _inst;
    static std::once_flag _done;
};

template <typename T>
std::once_flag Singleton<T>::_done;

template <typename T>
T* Singleton<T>::_inst = nullptr;

template <typename T>
T& Singleton<T>::Instance() {
    _inst = std::call_once(_done, [this]() {
        _inst = new T;
    });

    return _inst;
}

} // namespace Utility