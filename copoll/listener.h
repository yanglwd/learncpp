#pragma oncce

#include <string>

#include "../utility/nocopy.h"
#include "sock.h"

namespace CoNet
{

class Listener : public Utility::NoCopy
{
public:
    Listener() = default;
    ~Listener() { Destroy(); }

    bool Init(std::string addr, uint16_t port);
    void Destroy();

    Socket* Sock() { return _accept; }

private:
    Socket* _accept{nullptr};
};

} // namespace CoNet