#ifndef DOCTOR_DATA_2026_08_11
#define DOCTOR_DATA_2026_08_11
#include <string>


namespace star_map
{
    enum class System
    {
        Sol,
        BetaHydri,
        EpsilonEridani,
        AlphaCentauri,
        DeltaEridani,
        Omicron2Eridani
    };
}


namespace heaven
{

    class Vessel
    {




    public:

        int busters;
        star_map::System current_system;
        std::string name;
        int generation;


        Vessel (std::string name, int gen);
        Vessel(std::string name, int gen, star_map::System location);

        Vessel replicate(std::string name);

        void make_buster();
        bool shoot_buster();
    };

    std::string get_older_bob(Vessel a, Vessel b);
    bool in_the_same_system(Vessel a, Vessel b);


}


#endif
