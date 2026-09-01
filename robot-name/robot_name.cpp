#include "robot_name.h"

#include <ctime>

namespace robot_name {

    bool robot::seeded {false};
    std::unordered_set<std::string> robot::names {};

robot::robot()
{
    generate_name();

}

std::string robot::name() const
{
    return this->name_;
}

void robot::reset()
{
    generate_name();
}

void robot::generate_name()
{
    if (!seeded)
    {
        std::srand(static_cast<int>(std::time(nullptr)));
        seeded = true;
    }
    const char first_letter {static_cast<char>(65 + rand() % 26)};
    const char second_letter {static_cast<char>(65 + rand() % 26)};
    const int nr = rand() % 1000;
    do
    {
        this->name_ = "";
        this->name_.push_back(first_letter);
        this->name_.push_back(second_letter);
        // add leading 0s for small numbers and/or append the nr
        this->name_.append(
        (nr > 99 ? std::to_string(nr) :
         (nr > 9 ? "0" + std::to_string(nr)
              : "00" + std::to_string(nr))));

    }while (names.count(this->name_) != 0);

    names.insert(this->name_);
}
}  // namespace robot_name
