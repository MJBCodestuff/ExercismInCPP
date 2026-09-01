#include "power_of_troy.h"

namespace troy
{
    void give_new_artifact(human& owner, std::string_view artifact_name)
    {
        owner.possession = std::make_unique<artifact>(artifact_name.data());
    }

    void exchange_artifacts(std::unique_ptr<artifact>& artifact_1, std::unique_ptr<artifact>& artifact_2)
    {
        artifact_1.swap(artifact_2);

    }

    void manifest_power(human& owner, std::string_view power_name)
    {
        owner.own_power = std::make_shared<power>(power_name.data());
    }

    void use_power(human& user, human& target)
    {
        target.influenced_by = user.own_power;
    }

    int power_intensity(human& owner)
    {
        if (owner.own_power == nullptr)
            return 0;
        return static_cast<int>(owner.own_power.use_count());
    }

}  // namespace troy
