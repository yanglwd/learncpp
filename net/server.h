#pragma once

#include <string>
#include <thread>

#include "../co_net/sock.h"
#include "../utility/singleton.h"

namespace Net
{

struct ServerOption {
    std::string listenAddr;
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
    CoNet::Socket* _accept;
};

} // namespace Net