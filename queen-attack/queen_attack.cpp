#include "queen_attack.h"

#include <stdexcept>

namespace queen_attack {
    chess_board::chess_board(std::pair<int, int> white, std::pair<int, int> black)
    {
        if (white.first < 0 or white.second <0 or black.first <0 or black.second < 0
            or white.first >=8 or white.second >= 8 or black.first >= 8 or black.second >= 8
            or (white.first == black.first and white.second == black.second))
            throw std::domain_error("Invalid Position");

        this->white_ = white;
        this->black_ = black;
    }

    chess_board chess_board::board(std::pair<int, int> white, std::pair<int, int> black)
    {

        return {white, black};
    }

    std::pair<int, int> chess_board::white() const
    {
        return this->white_;
    }

    std::pair<int, int> chess_board::black() const
    {
        return this->black_;
    }

    bool chess_board::can_attack() const
    {
        return (this->white_.first == this->black_.first) or // same row
                (this->white_.second == this->black_.second) or // same column
                (std::abs(this->white_.first - this->black_.first) == // same diagonal
                    std::abs(this->white_.second - this->black_.second));
    }
}  // namespace queen_attack
