#include "raindrops.h"

namespace raindrops {
    std::string convert(int numberToConvert)
    {
        std::string result {};
        if (numberToConvert % 3 == 0)
            result.append("Pling");
        if (numberToConvert % 5 == 0)
            result.append("Plang");
        if (numberToConvert % 7 == 0)
            result.append("Plong");
        if (numberToConvert % 3 != 0
            && numberToConvert % 5 != 0
            && numberToConvert %7 != 0)
            result.append(std::to_string(numberToConvert));
        return result;
    }

}  // namespace raindrops
