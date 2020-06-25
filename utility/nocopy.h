#pragma once

namespace Utility
{

class NoCopy
{
public:
    NoCopy() = default;
    ~NoCopy() = default;
    NoCopy(const NoCopy&) = delete;
    NoCopy(NoCopy&&) = delete;
    NoCopy& operator=(const NoCopy&) = delete;
};

} // namespace Utility