#pragma once

#include "../utility/nocopy.h"

namespace CoNet {

class Socket : public Utility::NoCopy {
  public:
    Socket() = default;
    ~Socket() = default;

    bool Init();
    int Fd() { return _fd; }

  private:
    int _fd;
};

} // namespace CoNet