#include "series.h"
#include <stdexcept>

namespace series {

// TODO: add your solution here

std::vector<std::string> slice(std::string series, int slice_length) {
    if (slice_length > static_cast<int>(series.length())
        or slice_length < 1) throw std::domain_error("Slice Lengths is larger than series");
    std::vector<std::string> result {};

    for (int i {slice_length - 1}; i < static_cast<int>(series.length()); ++i) {
        result.emplace_back(series, i - (slice_length - 1), slice_length );
    }
    return result;
}
}  // namespace series
