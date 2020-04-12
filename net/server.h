#pragma once

#include <string>
#include <thread>

#include "../utility/singleton.h"

namespace Net
{

struct ServerOption {
    std::string listenAddr;
    uint16_t listenPort{0};
};

template <int E, int C>
class Server : public Utility::Singleton<Server>
{
public:
    Server() = default;
    ~Server() = default;

    bool Init(const ServerOption& opt);
    void Loop();
    void Destroy();

private:
};

} // namespace Net