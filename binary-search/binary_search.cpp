#include "binary_search.h"
#include <cmath>
#include <stdexcept>

namespace binary_search {


    //  ignoring any existing knowledge and just working from first principles without research
std::size_t find(std::vector<int> ordered_data, int value) {
    if (ordered_data.empty()
        or ordered_data.at(0) > value
        or ordered_data.at(ordered_data.size()-1) < value)
        throw std::domain_error("Invalid search");
    int index_value {0};
    int last_index_value {0};
    while (!ordered_data.empty()) {
        index_value = static_cast<int>(std::floor(ordered_data.size() / 2));
        const int current_examination = ordered_data.at(index_value);
        if (current_examination == value) return index_value + last_index_value;
        if (current_examination > value) {
            ordered_data = std::vector (ordered_data.begin(), ordered_data.begin() + index_value);
        }
        if (current_examination < value) {
            ordered_data = std::vector (ordered_data.begin() + index_value + 1, ordered_data.end());
            last_index_value += index_value + 1;
        }

    }
    throw std::domain_error("Value not found");
}
}  // namespace binary_search
