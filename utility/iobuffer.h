#pragma once

#include <memory>

namespace Utility {

class IOBuffer {
  public:
    IOBuffer(char* data, int size) { _buffer = std::unique_ptr<char>(new char[size]); }
    char* Get() { return _buffer.get(); }

  private:
    std::unique_ptr<char> _buffer;
};

} // namespace Utility