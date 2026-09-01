#pragma once
#include <utility>

namespace queen_attack {

class chess_board
{


    std::pair<int, int> white_;
    std::pair<int, int> black_;


public:

    chess_board (std::pair<int, int> white, std::pair<int, int> black);
    [[nodiscard]] static chess_board board(std::pair<int, int> white, std::pair<int, int> black);
    [[nodiscard]] std::pair<int, int> white() const;
    [[nodiscard]] std::pair<int, int> black() const;
    [[nodiscard]] bool can_attack() const;

};

}  // namespace queen_attack
