#include "grade_school.h"

#include <algorithm>

namespace grade_school {

    std::map<int, std::vector<std::string>> school::roster() const
    {
        return this->roster_data;
    }

    std::vector<std::string> school::grade(const int grade_nr) const
    {
        if (roster_data.empty()) return {};
        return roster_data.find(grade_nr)->second;

    }

    bool school::add(std::string_view name, const int grade_nr)
    {
        for (const std::string& taken_name : roster_data[grade_nr])
        {
            if (taken_name == name)
                return false;
        }
        roster_data[grade_nr].emplace_back(name);
        std::sort(roster_data[grade_nr].begin(), roster_data[grade_nr].end());
        return true;
    }
}  // namespace grade_school
