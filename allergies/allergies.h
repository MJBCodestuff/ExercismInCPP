#pragma once
#include <map>
#include <string>
#include <unordered_set>
#include <array>

namespace allergies {

    constexpr unsigned int allergies_to_test {8};

class allergy_test {
    unsigned int score;
    std::array<std::string, allergies_to_test> known_allergies
    {
        {
            "eggs", "peanuts", "shellfish", "strawberries", "tomatoes",
            "chocolate", "pollen", "cats"
        }};
    std::map<std::string, unsigned int> known_allergies_reverse_lookup {
        {"eggs", 1},
        {"peanuts", 2},
        {"shellfish", 4},
        {"strawberries", 8},
        {"tomatoes", 16},
        {"chocolate", 32},
        {"pollen", 64},
        {"cats", 128},
    };
    public:
    explicit allergy_test(int score);
    [[nodiscard]] bool is_allergic_to(std::string const &allergen) const;
    [[nodiscard]] std::unordered_set<std::string> get_allergies() const;
};
}  // namespace allergies
