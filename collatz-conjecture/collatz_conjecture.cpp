#include "collatz_conjecture.h"

#include <stdexcept>

namespace collatz_conjecture {
    int steps(int nr)
    {
        if (nr < 1) throw std::domain_error("Requires a positive integer");
        int counter{0};

        while (nr != 1)
        {
            if ((nr & 1) == 0)
                nr /= 2;
            else
                nr = nr * 3 + 1;
            ++counter;
        }
        return counter;
    }
}  // namespace collatz_conjecture
