#pragma once

#include <string>
#include <thread>

#include "../utility/singleton.h"

namespace Net {

struct ServerOption {
    std::string listenAddr;
    uint16_t listenPort{0};
    int epollCount{1};
    int epollCapacity{8 * 1024};
};

class Server : public Utility::Singleton<Server> {
  public:
    Server() = default;
    ~Server() = default;

    bool Init(const ServerOption& opt);
    void Loop();
    void Destroy();

  private:
};

} // namespace Net