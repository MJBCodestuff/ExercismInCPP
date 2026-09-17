#pragma once
#include <string>

namespace atbash_cipher {

    std::string encode(std::string input);
    std::string decode(std::string input);
    char switchLetter(char c);

}  // namespace atbash_cipher
