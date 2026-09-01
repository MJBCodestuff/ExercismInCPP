#pragma once

namespace triangle {

enum flavor
{
    equilateral,
    isosceles,
    scalene
};


bool is_triangle(double& a, double& b, double& c);
bool relative_float_equal(double a, double b, double e_rel);
bool float_equal(double a, double b, double e_rel, double e_abs);

flavor kind(double a, double b, double c);



}  // namespace triangle
