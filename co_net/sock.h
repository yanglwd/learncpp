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

    bool Send(char* data, uint32_t len);
    bool Recv(char* buffer, uint32_t& len);

private:
    void _OnIn();
    void _WaitIn();

    void _OnOut();
    void _WaitOut();

private:
    static int SendBufferSize;
    static int RecvBufferSize;
    static int SendLowAt;
    static int RecvLowAt;

    int _fd;
    std::weak_ptr<Epoll> _epoll;
};

} // namespace CoNet