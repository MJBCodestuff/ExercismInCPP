#include "allergies.h"

#include <bitset>

namespace allergies {
    allergy_test::allergy_test(const int score) {
        this->score = static_cast<unsigned int>(score);
    }


    bool allergy_test::is_allergic_to(std::string const &allergen) const {
        return (known_allergies_reverse_lookup.at(allergen) & score) ==
            known_allergies_reverse_lookup.at(allergen);
    }

    std::unordered_set<std::string> allergy_test::get_allergies() const {
        std::unordered_set<std::string> allergies {};
        const std::bitset<allergies_to_test> temp_score {score};
        for (unsigned int i = 0; i < allergies_to_test; ++i) {
            if (temp_score.test(i)) {
                allergies.emplace(known_allergies.at(i));
            }
        }
        return allergies;
    }
}  // namespace allergies
