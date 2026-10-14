#include "word_count.h"
#include <vector>
#include <sstream>
#include <cctype>

namespace word_count {
    std::map<std::string, int> words(std::string input_text) {
        std::vector<std::string> split_text{};
        for (int i = 0; i < static_cast<int>(input_text.length()); ++i) {
            if (ispunct(input_text[i]) or isspace(input_text[i])) {
                if (input_text[i] == '\'') {
                    if (i == 0 or i == static_cast<int>(input_text.length() - 1)  or !(isalnum(input_text[i-1]) and isalnum(input_text[i+1]))) {
                        input_text[i] = ' ';
                    }
                }else {
                    input_text[i] = ' ';
                }

            }

        }
        std::istringstream stream(input_text);
        std::string token;
        while (getline(stream, token, ' ' )) {
            if (!empty(token)) {
                std::transform(token.begin(), token.end(), token.begin(), [](char c){return std::tolower(c);});
                split_text.push_back(token);
            }
        }

    std::map<std::string, int> result{};
    for (std::string word : split_text){
        try {
            result.at(word) += 1;
        } catch (const std::out_of_range&) {
            result.emplace(word, 1);
        }
    }
    return result;
}

} // namespace word_count
