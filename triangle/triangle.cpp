#include "triangle.h"

#include <stdexcept>

namespace triangle {


    flavor kind(double a, double b, double c)
    {
        constexpr double e_rel{1e-8};
        constexpr double e_abs{1e-12};

        if (!is_triangle(a, b, c))
            throw std::domain_error("Not a triangle");
        if (float_equal(a, b, e_rel, e_abs) && float_equal(b, c, e_rel, e_abs))
            return flavor::equilateral;
        if (float_equal(a,b,e_rel,e_abs)
            || float_equal(a, c, e_rel, e_abs)
            || float_equal(b, c, e_rel, e_abs))
            return flavor::isosceles;
        return flavor::scalene;
    }

    bool is_triangle(double& a, double& b, double& c)
    {
        return (a > 0 && b > 0 && c > 0)
                && (
                       (a + b >= c)
                    && (a + c >= b)
                    && (b + c >= a));
    }

    bool relative_float_equal(double a, double b, double e_rel)
    {
        return (std::abs(a-b) <= (std::max (std::abs(a), std::abs(b)) * e_rel));
    }

    bool float_equal(double a, double b, double e_rel, double e_abs)
    {
        if (std::abs(a-b) <= e_abs)
            return true;
        return relative_float_equal(a, b, e_rel);
    }
}  // namespace triangle
