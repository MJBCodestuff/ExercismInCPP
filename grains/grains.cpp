#include "grains.h"

#include <cmath>

namespace grains {
    unsigned long long square(int s)
    {
        return static_cast<unsigned long long> (std::pow(2.0, static_cast<double> (s-1)));
    }

    unsigned long long total()
    {
        unsigned long long rice{0};
        for (int i = 1; i <= 64; ++i)
        {
            rice += square(i);

        }
        return rice;
    }
}  // namespace grains
