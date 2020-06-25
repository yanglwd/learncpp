#pragma once

#include <list>
#include <mutex>

namespace Utility
{

template <typename T>
class Queue : public NoCopy
{
public:
    Queue() = default;
    ~Queue() { _Destroy(); }

    void Push(T& data);
    T Pop();

private:
    void _Destroy() { _valid = false; }

    std::list<T> _queue;
    std::mutex _mtx;
};

template <typename T>
void Queue<T>::Push(T& data)
{
    std::lock_guard lg(_mtx);
    if (!_valid) {
        return
    }

    _queue.insert(data);
}

template <typename T>
T Queue<T>::Pop()
{
    std::lock_guard lg(_mtx);
    if (!_valid) {
        return
    }

    T tmp = _queue.front();
    _queue.pop_front();
    return tmp;
}
} // namespace Utility