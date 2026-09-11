#include "clock.h"



namespace date_independent {



clock::clock(int hour, int minutes) {
    this -> hour = hour;
    this -> minutes = minutes;
}

clock clock::at(int hour, int minutes) {
    hour += minutes/60;
    if (minutes < 0) {
        // above takes care of loosing more than one hour,
        // but one additional needs to be lost every time we have negative minutes
        --hour;
        minutes %= 60;
        minutes += 60;
    }
    minutes %= 60;

    if (hour < 0) {
        hour %= 24;
        hour = 24 + hour;
    }else {
        hour %= 24;
    }
    return {hour, minutes};
}

clock clock::plus(int additional_minutes) const {
    int additional_hours = additional_minutes / 60;
    int temp_minutes = this->minutes;
    int temp_hour = this->hour;

    temp_minutes += (additional_minutes % 60);
    // check for any additional rollover
    additional_hours += temp_minutes / 60;
    temp_minutes %= 60;

    temp_hour += additional_hours;
    temp_hour %= 24;

    return at(temp_hour, temp_minutes);

}

clock clock::minus(int removed_minutes) const {
    return plus(removed_minutes * -1);
}

bool clock::operator==(clock c) const {
    return this->hour == c.hour && this->minutes == c.minutes;
}

bool clock::operator!=(clock c) const {
    return !operator==(c);
}

clock::operator std::string() const {
    // no c++20, no easy formating
    std::string result {};
    if (hour < 10)
        result.append("0");
    result.append(std::to_string(hour));
    result.append(":");
    if (minutes < 10)
        result.append("0");
    result.append(std::to_string(minutes));
    return result;
}
}  // namespace date_independent
