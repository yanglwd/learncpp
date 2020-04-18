#pragma once

#include <functional>
#include <sys/epoll.h>

#include "../utility/nocopy.h"

namespace CoNet
{

class Epoll : public Utility::NoCopy
{
public:
    Epoll() = default;
    ~Epoll() = default;

    bool Init();
    void Loop();
    void Destroy();

    bool Add(int fd);
    bool Mod(int fd);
    bool Del(int fd);

private:
    int _efd{-1};
};

} // namespace CoNet