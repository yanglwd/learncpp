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
    Socket(std::shared_ptr<Epoll> ep);
    ~Socket();

    bool Init();
    void Destroy();

    int Fd() { return _fd; }

private:
    static int SendBufferSize;
    static int RecvBufferSize;
    static int SendLowAt;
    static int RecvLowAt;

    int _fd;
    std::weak_ptr<Epoll> _epoll;
};

} // namespace CoNet