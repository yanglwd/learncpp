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

bool Conn::_Send(char* data, int len)
{
    return true;
}

bool Conn::_Recv(char* data, int len)
{
    return true;
}

} // namespace CoNet