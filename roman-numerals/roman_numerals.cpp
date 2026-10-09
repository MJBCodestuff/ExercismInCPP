#include "roman_numerals.h"

#include <vector>
#include <stdexcept>

namespace roman_numerals {
    std::string convert(const int arabic_number) {
        if (arabic_number < 1 or arabic_number >= 4000) throw std::out_of_range("Only positive values up to 3999 allowed");
        std::string result {};
        std::vector digits {arabic_number / 1000, (arabic_number / 100) % 10, (arabic_number / 10) % 10, arabic_number % 10};
        std::vector lookup {{'I', 'V', 'X', 'L', 'C', 'D', 'M', '0', '0'}};
        for (int i = 0; i < 4; ++i) {
            const int digit = digits.at(i);
            if (digit == 0) continue;
            std::string temp {generic_digit_converter(digit)};
            std::vector current_lookup (lookup.end() - 3 - (2 * i), lookup.end() - (2 * i));
            for (const char coded_numeral: temp) {
                result.push_back(current_lookup.at(coded_numeral - '1')); // using 1 for conversion to compensate for 0 based vector
            }
        }
        return result;

    }

    // returns for a given digit a generic code
    // 1 is the lowest roman number in the range, 2 the mid number, 3 the upper bound
    std::string generic_digit_converter(int digit) {
        std::string result {};
        if (digit == 0) return ""; // 0 is nothing in roman numbers
        if (digit == 4) result.push_back('1'); // prefix for 4
        if (digit >= 4 and digit < 9) { // covering every case where middle letter is required
            result.push_back('2');
        }
        if (digit < 9 and digit != 4) { // suffix lowest letter(s)
            if (digit >= 5) digit -= 5;
            for (int i = 0; i < digit; ++i) {
                result.push_back('1');
            }
        }
        if (digit == 9){
            result = "13"; //special case for 9
        }
        return result;

    }
}  // namespace roman_numerals
