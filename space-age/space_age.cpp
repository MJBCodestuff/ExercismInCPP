#include "space_age.h"

namespace space_age {

    constexpr double MERCURY_ORBITAL_PERIOD = 0.2408467;
    constexpr double VENUS_ORBITAL_PERIOD = 0.61519726;
    constexpr double MARS_ORBITAL_PERIOD = 1.8808158;
    constexpr double JUPITER_ORBITAL_PERIOD = 11.862615;
    constexpr double SATURN_ORBITAL_PERIOD = 29.447498;
    constexpr double URANUS_ORBITAL_PERIOD = 84.016846;
    constexpr double NEPTUNE_ORBITAL_PERIOD = 164.79132;

    space_age::space_age(long seconds)
    {
        this->age = seconds;
    }

    long space_age::seconds() const
    {
        return this->age;
    }

    double space_age::on_earth() const
    {
        return (static_cast<double>(this->age) / 60 /60/24/365.25);
    }

    double space_age::on_mercury() const
    {
        return on_earth() / MERCURY_ORBITAL_PERIOD;
    }

    double space_age::on_venus() const
    {
        return on_earth() / VENUS_ORBITAL_PERIOD;
    }

    double space_age::on_mars() const
    {
        return on_earth() / MARS_ORBITAL_PERIOD;
    }

    double space_age::on_jupiter() const
    {
        return on_earth() / JUPITER_ORBITAL_PERIOD;
    }

    double space_age::on_saturn() const
    {
        return on_earth() / SATURN_ORBITAL_PERIOD;
    }

    double space_age::on_uranus() const
    {
        return on_earth() / URANUS_ORBITAL_PERIOD;
    }

    double space_age::on_neptune() const
    {
        return on_earth() / NEPTUNE_ORBITAL_PERIOD;
    }
}  // namespace space_age
