#include <arpa/inet.h>
#include <memory>
#include <string.h>

#include "listener.h"

namespace CoNet
{

bool Listener::Init(std::string addr, uint16_t port)
{
    _accept = new CoNet::Socket();

    if (!_accept->Init()) {
        return false;
    }

    sockaddr_in in;
    bzero(&in, sizeof(in));

    in.sin_family = AF_INET;
    in.sin_port = htons(port);
    if (1 != inet_pton(AF_INET, addr.c_str(), &in.sin_addr)) {
        return false;
    }

    if (bind(_accept->Fd(), (sockaddr*)&in, sizeof(in)) < 0) {
        return false;
    }

    if (listen(_accept->Fd(), 2048) < 0) {
        return false;
    }

    return true;
}

void Listener::Destroy()
{
    if (nullptr != _accept) {
        delete _accept;
    }

    _accept = nullptr;
}

} // namespace CoNet