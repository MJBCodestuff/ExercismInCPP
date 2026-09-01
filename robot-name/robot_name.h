#pragma once
#include <string>
#include <unordered_set>

namespace robot_name {


class robot
{
    static bool seeded;
    static std::unordered_set<std::string> names;
    std::string name_;

    public:

    robot();
    [[nodiscard]] std::string name() const;
    void reset();
    void generate_name();
};
}  // namespace robot_name
