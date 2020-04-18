#include <exception>
#include <sys/epoll.h>
#include <sys/signal.h>
#include <unistd.h>

#include "epoll.h"

namespace CoNet
{

const int MAX_FD_SIZE = 8 * 1024;

bool Epoll::Init()
{
    signal(SIGPIPE, SIG_IGN);

    _efd = epoll_create1(EPOLL_CLOEXEC);
    if (-1 == _efd) {
        return false;
    }
    return true;
}

void Epoll::Loop()
{
    int cnt = 0;
    epoll_event evts[MAX_FD_SIZE];
    for (;;) {
        cnt = epoll_wait(_efd, evts, MAX_FD_SIZE, -1);
    }
}

void Epoll::Destroy()
{
    close(_efd);
}

bool Epoll::Add(int fd)
{
    try {
        epoll_event evt;
        evt.data.fd = fd;
        evt.events = EPOLLIN | EPOLLET;
        return 0 == epoll_ctl(_efd, EPOLL_CTL_ADD, fd, &evt);
    } catch (const std::exception&) {
        // TODO
    }

    return false;
}

bool Epoll::Mod(int fd)
{
    return false;
}

bool Epoll::Del(int fd)
{
    try {
        return 0 == epoll_ctl(_efd, EPOLL_CTL_ADD, fd, nullptr);
    } catch (const std::exception&) {
        // TODO
    }

    return false;
}

} // namespace CoNet