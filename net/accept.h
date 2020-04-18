#pragma once

#include <atomic>
#include <functional>
#include <string>
#include <thread>

#include "../co_net/sock.h"
#include "../utility/nocopy.h"

namespace Net
{

using NEW_CONN = std::function<void(CoNet::Socket*)>;

class Acceptor : public Utility::NoCopy
{
public:
    Acceptor() = default;
    ~Acceptor() = default;

    bool Init(std::string addr, uint16_t port);
    void Loop();
    void Destroy();

private:
    static NEW_CONN OnNewConn;

    CoNet::Socket* _accept{nullptr};
    std::thread* _thrd{nullptr};
    std::atomic_bool _stop;
};

} // namespace Net