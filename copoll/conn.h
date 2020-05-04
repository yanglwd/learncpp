#pragma once

#include <deque>

#include "../utility/queue.h"
#include "sock.h"

namespace CoNet
{

class Conn : public Utility::NoCopy
{
public:
    Conn(Socket* s);
    ~Conn();

    virtual bool Send(char* data, int len);
    virtual bool Recv(char* buffer, int len);

private:
    Socket* _socket{nullptr};
};

using SHARED_CONN = std::shared_ptr<Conn>;
using WEAK_CONN = std::weak_ptr<Conn>;

} // namespace CoNet
