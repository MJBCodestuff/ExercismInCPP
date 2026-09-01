#include "say.h"

#include <stdexcept>

namespace say {
    std::string in_english(const long number)
    {
        if (number > 999'999'999'999 or number < 0) throw std::domain_error("Number out of range");
        if (number == 0) // handling the special case
            return "zero";
        std::string result = in_english_recurse(number);
        if (isblank(result.back())) // numbers ending in 00 create a trailing whitespace
                                    // removing them here is simpler
            result = result.substr(0, result.length()-1);
        return result;
    }

    std::string in_english_recurse(const long number)
    {
        const std::string numberStr {std::to_string(number)};
        if (numberStr == "0") // a zero here is only encountered on multi digit numbers ending in zero
            return "";
        // larger numbers
        if (numberStr.length() > 9)
            return in_english_recurse(std::stol(numberStr.substr(0, (numberStr.length() - 9))))
            + " billion "
            + in_english_recurse(std::stol(numberStr.substr((numberStr.length() - 9))));
        if (numberStr.length() > 6)
            return in_english_recurse(std::stol(numberStr.substr(0, (numberStr.length() - 6))))
            + " million "
            + in_english_recurse(std::stol(numberStr.substr((numberStr.length() - 6))));
        if (numberStr.length() > 3)
            return in_english_recurse(std::stol(numberStr.substr(0, (numberStr.length() - 3))))
            + " thousand "
            + in_english_recurse(std::stol(numberStr.substr((numberStr.length() - 3))));
        if (numberStr.length() > 2)
            return in_english_recurse(std::stol(numberStr.substr(0, 1)))
                + " hundred " +
                in_english_recurse(std::stol(numberStr.substr(1)));
        // numbers thirteen and below follow a different pattern than 14-19 and need to be looked up
        if (number < 14)
            return numberToWord[number];
        if (number < 20)
            return numberToWord[std::stoi(numberStr.substr(1,1))] + "teen";
        // pattern for numbers 20-90 ending in zero
        if (number % 10 == 0)
            return prefixes[std::stol(numberStr.substr(0, 1))] + "ty";
        //everything between 20 and 99 not ending in 0
        return in_english_recurse(number - (number % 10))
        + "-"
        + in_english_recurse(std::stol(numberStr.substr(1,1)));




    }
}  // namespace say
