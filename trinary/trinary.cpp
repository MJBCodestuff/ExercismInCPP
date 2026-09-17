#include "trinary.h"
#include <cmath>

namespace trinary {


int to_decimal(std::string trinary_number) {
    if (trinary_number.find_first_not_of("012") != std::string::npos)
        return 0;
    int result {0};
    for (int i = static_cast<int>(trinary_number.length() -1 ); i >= 0; --i) {
        result += (trinary_number.at(i) - '0') * static_cast<int>(std::pow(3, trinary_number.length() - (i+1)));

    }
    return result;
}
}  // namespace trinary
