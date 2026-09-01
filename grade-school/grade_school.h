#pragma once
#include <map>
#include <string>
#include <vector>

namespace grade_school {

    class school
    {
        std::map<int, std::vector<std::string>> roster_data{};
    public:

        std::map<int, std::vector<std::string>> roster() const;
        std::vector<std::string> grade(int grade_nr) const;
        bool add(std::string_view name, int grade_nr);

    };

}  // namespace grade_school
