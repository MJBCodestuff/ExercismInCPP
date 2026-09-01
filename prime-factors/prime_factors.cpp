#include "prime_factors.h"

#include <cmath>

namespace prime_factors {

std::vector<long long> of(long long nr)
{
    if (nr == 1) return {};
    std::vector<long long> result {};
    if ((nr & 0x1) == 0)
    {
        result.push_back(2);
        std::vector<long long> temp = of(nr / 2);
        result.insert(result.end(), temp.begin(), temp.end() );
        return result;
    }
    for (int i = 3; i <= nr; i+=2)
    {
        if (nr % i == 0)
        {
            result.push_back(i);
            std::vector<long long> temp = of(nr / i);
            result.insert(result.end(), temp.begin(), temp.end());
            return result;
        }
    }
    return {};
}
}  // namespace prime_factors
