#pragma once

#include <deque>

#include "../utility/nocopy.h"
#include "../utility/queue.h"

namespace CoNet {

class Conn : public Utility::NoCopy {
  public:
    Conn() = default;
    ~Conn() = default;

    virtual bool Send(char* data, int len) = 0;
    virtual bool Recv(char* buffer, int len) = 0;

  protected:
    bool _Send(char* data, int len);
    bool _Recv(char* data, int len);

  private:
    Utility::Queue<char>::Queue _waitSend;
};

} // namespace CoNet
