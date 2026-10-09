#include "bob.h"
#include <cctype>
#include <algorithm>

namespace bob {
    std::string trim(std::string_view input) {
        std::string_view::const_iterator start = input.begin();
        std::string_view::const_iterator end = input.end();

        while (start < end && std::isspace(*start)) {
            ++start;
        }
        do {
            --end;
        }while (end > start && std::isspace(*end));
        return {start, end +1};
    }

std::string hey(std::string input) {
    input = trim(input);
    const bool is_all_caps = std::all_of(input.begin(), input.end(), [](char c) {
        return !std::islower(c);
    })
    and
    std::any_of(input.begin(), input.end(), [](char c) {
        return std::isalpha(c);
    });
    const bool question = input.back() == '?';
    if (question and !is_all_caps)
        return "Sure.";
    if (!question and is_all_caps)
        return "Whoa, chill out!";
    if (question and is_all_caps)
        return "Calm down, I know what I'm doing!";
    if (input.empty())
        return "Fine. Be that way!";
    return "Whatever.";
}
}  // namespace bob
