#include "doctor_data.h"


namespace heaven
{
    Vessel::Vessel (std::string name, int gen)
    {
        this->name = name;
        this->generation = gen;
        this->current_system = star_map::System::Sol;
        this->busters = 0;
    }

    Vessel::Vessel(std::string name, int gen, star_map::System location)
    {
        this->name = name;
        this->generation = gen;
        this->current_system = location;
        this->busters = 0;
    }

    Vessel Vessel::replicate(std::string name)
    {
        return Vessel(name, this->generation + 1, this->current_system);
    }

    void Vessel::make_buster()
    {
        ++this->busters;
    }

    bool Vessel::shoot_buster()
    {
        if (this->busters == 0)
            return false;
        --this->busters;
        return true;
    }

    std::string get_older_bob(Vessel a, Vessel b)
    {
        if (a.generation <= b.generation) return a.name;
        return b.name;
    }

    bool in_the_same_system(Vessel a, Vessel b)
    {
        return a.current_system == b.current_system;
    }
}
