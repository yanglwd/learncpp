#pragma once

#include <string>
#include <thread>
#include <unordered_map>

#include "../copoll/epoll.h"
#include "../utility/singleton.h"

namespace Net
{

struct ServerOption {
    std::string listenAddr{"0.0.0.0"};
    uint16_t    listenPort{0};
};

class Server : public Utility::Singleton<Server>
{
public:
    Server() = default;
    ~Server() = default;

    bool Init(const ServerOption& opt);
    void Loop();
    void Destroy();

private:
    bool _Listen(std::string addr, uint16_t port);

private:
    using SOCK_MAP = std::unordered_map<uint32_t, SOCK_PTR>;
    using EPOLL_PTR = std::shared_ptr<>;

    CoNet::Epoll* _ep;
    SOCK_MAP      _conns;
};

} // namespace Net