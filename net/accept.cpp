#include <arpa/inet.h>
#include <string.h>

#include "accept.h"

namespace Net
{

NEW_CONN Acceptor::OnNewConn;

bool Acceptor::Init(std::string addr, uint16_t port)
{
    _accept = new CoNet::Socket;
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

    _thrd = new std::thread([this]() {
        Loop();
    });
    return true;
}

void Acceptor::Loop()
{
    for (;;) {
        sockaddr remote;
        bzero(&remote, sizeof(remote));

        socklen_t len = 0;
        int s = accept(_accept->Fd(), &remote, &len);
        if (s < 0) {
            continue;
        }
    }
}

void Acceptor::Destroy()
{
    _stop.store(true);
    _thrd->join();

    _accept->Destroy();
}

} // namespace Net