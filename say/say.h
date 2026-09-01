#pragma once
#include <map>
#include <string>

namespace say {
    inline std::map<long, std::string> numberToWord{
        {1, "one"},
        {2, "two"},
        {3, "three"},
        {4, "four"},
        {5, "five"},
        {6, "six"},
        {7, "seven"},
        {8, "eight"},
        {9, "nine"},
        {10, "ten"},
        {11, "eleven"},
        {12, "twelve"},
        {13, "thirteen"}
    };

    inline std::map<long, std::string> prefixes {
        {2, "twen"},
        {3, "thir"},
        {4, "for"},
        {5, "fif"},
        {6, "six"},
        {7, "seven"},
        {8, "eigh"},
        {9, "nine"}
    };
    std::string in_english(long number);
    std::string in_english_recurse(long number);

}  // namespace say
