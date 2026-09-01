#include "pangram.h"

#include <algorithm>
#include <list>
#include <vector>

namespace pangram {
    bool is_pangram(const std::string_view sentence)
    {
        std::list<char> alphabet{};
        for (char c = 'a'; c <= 'z'; ++c)
        {
            alphabet.emplace_back(c);
        }

        for (int i = 0; i < static_cast<int>(sentence.length()); ++i)
        {

            if (std::find(alphabet.begin(), alphabet.end(), std::tolower(sentence.at(i)))
                != alphabet.end())
                alphabet.remove(static_cast<char> (std::tolower(sentence.at(i))));

        }
        if (alphabet.empty())
            return true;
        return false;
    }
}  // namespace pangram
