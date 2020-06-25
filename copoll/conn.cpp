#include "conn.h"

namespace CoNet
{

Conn::Conn(Socket* s)
{
    _socket = s;
}

Conn::~Conn()
{
    if (nullptr != _socket) {
        delete _socket;
    }
}

bool Conn::Send(char* data, int len)
{
    if (nullptr == _socket) {
        return false;
    }

    return _socket->Send(data, len);
}

bool Conn::Recv(char* data, int len)
{
    if (nullptr == _socket) {
        return false;
    }
    return true;
}

} // namespace CoNet