#pragma once
#include <string>

namespace date_independent {

class clock {

    int hour;
    int minutes;
    clock(int hour, int minutes);
    public:
    static clock at(int hour, int minutes);
    [[nodiscard]] clock plus(int additional_minutes) const;
    [[nodiscard]] clock minus(int removed_minutes) const;
    bool operator== (clock c) const;
    bool operator!= (clock c) const;
    operator std::string() const;
};
}  // namespace date_independent
