#include <arpa/inet.h>
#include <string.h>
#include <sys/socket.h>

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
    _accept = std::make_shared<CoNet::Socket>(new CoNet::Socket(_ep));
    if (nullptr == _accept) {
        return false;
    }

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

} // namespace Net