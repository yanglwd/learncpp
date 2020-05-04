#include "server.h"

namespace Net
{

bool Server::Init(const ServerOption& opt)
{
    _ep = std::make_shared<CoNet::Epoll>(new CoNet::Epoll);
    if (nullptr == _ep) {
        return false;
    }

    if (!_Listen(opt.listenAddr, opt.listenPort)) {
        return false;
    }

    return true;
}

bool Server::_Listen(std::string addr, uint16_t port)
{

    return true;
}

} // namespace Net