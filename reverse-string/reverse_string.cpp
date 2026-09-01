#include "reverse_string.h"

#include <vector>

namespace reverse_string {

    std::string reverse_string(std::string inputString)
    {
        std::string result (rbegin(inputString), rend(inputString));
        return result;
    }
}  // namespace reverse_string
