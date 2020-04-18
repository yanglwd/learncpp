#pragma once

#include <functional>

#include "../utility/nocopy.h"

namespace CoNet
{

class Socket : public Utility::NoCopy
{
public:
    Socket() = default;
    ~Socket() = default;

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

} // namespace CoNet