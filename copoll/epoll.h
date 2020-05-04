#pragma once

#include <functional>
#include <sys/epoll.h>

#include "../utility/nocopy.h"
#include "conn.h"

namespace CoNet
{

struct ConnEvent {
    Conn* conn;
    bool  accept;
};

class Epoll : public Utility::NoCopy
{
public:
    Epoll() = default;
    ~Epoll() = default;

    bool Init();
    void Loop();
    void Destroy();
    bool Add(ConnEvent* ce);
    bool Mod(ConnEvent* ce);
    bool Del(ConnEvent* ce);

private:
    int _efd{-1};
};

} // namespace CoNet