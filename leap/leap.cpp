#include "leap.h"

namespace leap {
    bool is_leap_year(int year)
    {
        // a number is evenly divisible by 4 if the two lsb are 0
        return ((year &0b11) == 0) && ((year % 100 != 0) || (year % 400 == 0));
    }
}  // namespace leap
