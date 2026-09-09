#include "secret_handshake.h"
#include <bitset>
#include <stdexcept>
#include <algorithm>
namespace secret_handshake {

std::vector<std::string> commands(int arg) {
    if (arg < 0 or arg > 31) throw std::domain_error("Value outside range");
    std::bitset<5> arg_as_bits{static_cast<unsigned int>(arg)};
    std::vector<std::string> result {};
    if (arg_as_bits.test(0)) result.emplace_back("wink");
    if (arg_as_bits.test(1)) result.emplace_back("double blink");
    if (arg_as_bits.test(2)) result.emplace_back("close your eyes");
    if (arg_as_bits.test(3)) result.emplace_back("jump");
    if (arg_as_bits.test(4)) std::reverse(result.begin(), result.end());
    return result;
}
}  // namespace secret_handshake
