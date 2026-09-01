#include "nth_prime.h"

#include <array>
#include <cmath>
#include <stdexcept>

namespace nth_prime {

    /*
     *@brief Calculates the n-th prime using the sieve of Eratosthenes
     *
     *
     * Assumes n-th prime < n^2
     *
     *
     */
    int nth(int n)
    {
        if (n < 1) throw std::domain_error("Invalid n");
        // 1^2 < 2 -> needs to be caught here
        if (n == 1) return 2;
        int size = static_cast<int>(std::pow(n, 2));
        bool* sieve = new bool[size * sizeof(bool)];

        //  ensure defined values for indices >= 2
        for (int i = 2; i < size; ++i)
        {
            *(sieve + i) = true;
        }

        // 0 and 1 are not prime
        int current = {2};
        for (int i = 1; i <= n; ++i)
        {
            // find first true in vector, that's the next prime
            for (int ii = current; ii < size; ++ii)
            {
                if (*(sieve + ii) == true)
                {
                    current = ii;
                    break;
                }
            }

            // flip the found prime and all multiples of it
            for (int ii = current; ii < size; ii += current)
            {
                *(sieve + ii) = false;
            }

        }

        delete[] sieve;
        return current;

    }
}  // namespace nth_prime
