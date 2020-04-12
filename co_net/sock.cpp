#include <fcntl.h>
#include <sys/socket.h>

#include "sock.h"

namespace CoNet
{

bool Socket::Init()
{
    int tmp = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == tmp) {
        return false;
    }

    _fd = tmp;
    return true;
}

} // namespace CoNet