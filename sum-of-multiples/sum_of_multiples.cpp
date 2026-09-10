#include "sum_of_multiples.h"

#include <numeric>
#include <algorithm>

namespace sum_of_multiples {


int to(const std::vector<int> &items, const int level) {
    std::vector<int> multiples {};
    for (const int item : items) {
        for (int i = item; i < level; i+=item) {
            multiples.emplace_back(i);
        }
    }
    std::sort(multiples.begin(), multiples.end());
    const auto last = std::unique(multiples.begin(), multiples.end());
    multiples.erase(last, multiples.end());
    return std::reduce(multiples.begin(), multiples.end(), 0);
}
}  // namespace sum_of_multiples
