#include "nucleotide_count.h"

#include <stdexcept>

namespace nucleotide_count {
    std::map<char, int> count(std::string sequence)
    {
        std::map<char, int> counter {{'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}};
        try
        {
            for (int i = 0; i < static_cast<int>(sequence.length()); ++i)
            {
                ++counter.at(sequence.at(i));
            }
        }
        catch (std::out_of_range&)
        {
            throw std::invalid_argument("Invalid nucleotide detected");
        }
        return counter;
    }
}  // namespace nucleotide_count
