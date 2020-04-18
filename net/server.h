#pragma once

#include <string>
#include <thread>

#include "../utility/singleton.h"
#include "accept.h"

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
    Acceptor* _accept;
};

} // namespace Net