#pragma once

#include <functional>
#include <memory>

#include "../utility/nocopy.h"
#include "epoll.h"

namespace CoNet
{

class Socket : public Utility::NoCopy
{
public:
    Socket() = default;
    ~Socket() { Destroy(); }

    bool Init();
    void Destroy();

    int Fd() { return _fd; }

private:
    static int SendBufferSize;
    static int RecvBufferSize;
    static int SendLowAt;
    static int RecvLowAt;

    int _fd;
};

// using SHARED_SOCK = std::shared_ptr<Socket>;
// using WEAK_SOCK = std::weak_ptr<Socket>;

} // namespace CoNet