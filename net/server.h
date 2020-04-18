#pragma once

#include <string>
#include <thread>
#include <unordered_map>

#include "../co_net/sock.h"
#include "../utility/singleton.h"

namespace Net
{

struct ServerOption {
    std::string listenAddr{"0.0.0.0"};
    uint16_t listenPort{0};
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
    using SOCK_PTR = std::shared_ptr<CoNet::Socket>;
    using SOCK_MAP = std::unordered_map<uint32_t, SOCK_PTR>;
    using EPOLL_PTR = std::shared_ptr<CoNet::Epoll>;

    EPOLL_PTR _ep;
    SOCK_PTR _accept;
    SOCK_MAP _conns;
};

} // namespace Net