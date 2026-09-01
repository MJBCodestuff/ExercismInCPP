#include "hamming.h"

#include <stdexcept>

namespace hamming {
    int compute(std::string sequence_1, std::string sequence_2)
    {
        if (sequence_1.length() != sequence_2.length())
            throw std::domain_error("Different sequence lengths");
        int counter{0};
        for (int i = 0; i < static_cast<int>(sequence_1.length()); ++i)
        {
            if (sequence_1.at(i) != sequence_2.at(i))
                ++counter;

        }
        return counter;
    }
}  // namespace hamming
