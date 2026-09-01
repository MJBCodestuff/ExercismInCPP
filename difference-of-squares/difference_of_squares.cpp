#include "difference_of_squares.h"

#include <algorithm>
#include <chrono>
#include <cmath>
#include <numeric>
#include <vector>

namespace difference_of_squares {
    int square_of_sum(int n)
    {
        std::vector<int> numbers;
        std::generate_n(std::back_inserter(numbers), n, [counter = 0]() mutable
        {
            return ++counter;
        });
        const int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
        return static_cast<int>(std::pow(sum, 2));
    }

    int sum_of_squares(int n)
    {
        std::vector<int> numbers;
        std::generate_n(std::back_inserter(numbers), n, [counter = 1]() mutable
        {
            const int result = static_cast<int>(std::pow(counter, 2));
            ++counter;
            return result;
        });
        return std::accumulate(numbers.begin(), numbers.end(), 0);
    }

    int difference(int n)
    {
        return std::abs(square_of_sum(n) - sum_of_squares(n));

    }
}  // namespace difference_of_squares
