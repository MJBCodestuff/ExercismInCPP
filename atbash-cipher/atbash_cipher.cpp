#include "atbash_cipher.h"
#include <vector>

namespace atbash_cipher {



std::string encode(std::string input) {
    std::vector<char> result_vector {};
    int blank_counter {0};

    for (int i = 0; i < static_cast<int>(input.length()); ++i) {
        if (isnumber(input.at(i)))
            result_vector.emplace_back(input.at(i));

        if (isalpha(input.at(i)))
            result_vector.emplace_back(switchLetter(tolower(input.at(i))));

        if ((result_vector.size() - blank_counter) % 5 == 0
            and result_vector.at(result_vector.size() -1) != ' ') {
            result_vector.emplace_back(' ');
            ++blank_counter;
        }


    }
    if (result_vector.at(result_vector.size() -1 ) == ' ')
        result_vector.pop_back();
    return {result_vector.begin(), result_vector.end()};
}

std::string decode(std::string input) {
    std::vector<char> result_vector {};
    for (int i = 0; i < static_cast<int>(input.length()); ++i) {
        if (isnumber(input.at(i)))
            result_vector.emplace_back(input.at(i));
        if (isalpha(input.at(i)))
            result_vector.emplace_back(switchLetter(tolower(input.at(i))));
    }
    return {result_vector.begin(), result_vector.end()};
}

char switchLetter(char c) {
    constexpr char lower_offset {97};
    return 'z' - (c - lower_offset);
}
}  // namespace atbash_cipher
