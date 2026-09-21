#pragma once
#include <string>

namespace phone_number {

class phone_number {

    std::string clean_number;

    public:
    phone_number(const std::string& nr);
    [[nodiscard]] std::string number() const;
};

}  // namespace phone_number
