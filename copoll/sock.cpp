#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <sys/fcntl.h>
#include <sys/socket.h>
#include <unistd.h>

#include "epoll.h"
#include "sock.h"

namespace CoNet
{

int Socket::SendBufferSize = 8 * 1024;
int Socket::RecvBufferSize = 8 * 1024;
int Socket::SendLowAt = 0;
int Socket::RecvLowAt = 0;

bool Socket::Init()
{
    int tmp = socket(AF_INET, SOCK_STREAM, 0);
    if (tmp < 0) {
        return false;
    }

    int v = 1;
    setsockopt(tmp, SOL_SOCKET, SO_KEEPALIVE, &v, sizeof(v));
    setsockopt(tmp, SOL_SOCKET, SO_REUSEADDR, &v, sizeof(v));
    setsockopt(tmp, IPPROTO_TCP, TCP_NODELAY, &v, sizeof(v));

    v = RecvBufferSize;
    setsockopt(tmp, SOL_SOCKET, SO_RCVBUF, &v, sizeof(v));

    v = SendBufferSize;
    setsockopt(tmp, SOL_SOCKET, SO_SNDBUF, &v, sizeof(v));

    v = SendLowAt;
    setsockopt(tmp, SOL_SOCKET, SO_SNDLOWAT, &v, sizeof(v));

    v = RecvLowAt;
    setsockopt(tmp, SOL_SOCKET, SO_RCVLOWAT, &v, sizeof(v));

    linger l;
    l.l_linger = 1;
    l.l_onoff = 1;
    setsockopt(tmp, SOL_SOCKET, SO_LINGER, &l, sizeof(l));

    v = fcntl(tmp, F_GETFL, 0);
    if (v < 0) {
        return false;
    }

    v |= O_NONBLOCK;
    if (fcntl(tmp, F_SETFL, v) < 0) {
        return false;
    }

    _fd = tmp;
    return true;
}

void Socket::Destroy()
{
    if (-1 != _fd) {
        close(_fd);
    }

    _fd = -1;
}

} // namespace CoNet