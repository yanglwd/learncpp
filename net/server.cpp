#include "server.h"

namespace Net
{

bool Server::Init(const ServerOption& opt)
{
    _accept = new (CoNet::Socket);

    return true;
}

} // namespace Net