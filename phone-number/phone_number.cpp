#include "phone_number.h"


#include <vector>
#include <stdexcept>


namespace phone_number {

phone_number::phone_number(const std::string& nr) {
    std::vector<char> numbers {};
    for (char symbol: nr) {
        if (isdigit(symbol)) numbers.emplace_back(symbol);
    }
    if (numbers[0] == '1') numbers = std::vector(numbers.begin() + 1, numbers.end());

    if (numbers.size() != 10
        or numbers[0] < '2'
        or numbers [3] < '2') throw std::domain_error("Invalid Number");
    this->clean_number = {numbers.begin(), numbers.end()};
}

std::string phone_number::number() const {

    return clean_number;
}
}  // namespace phone_number
