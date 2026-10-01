#pragma once
#include <cmath>

namespace complex_numbers {



class Complex {

    double real_part;
    double imaginary_part;
public:
    Complex(double real, double imaginary);
    [[nodiscard]] double real() const;
    [[nodiscard]] double imag() const;
    Complex operator*(Complex c2) const;
    Complex operator*(double d) const;
    Complex operator+(Complex c2) const;
    Complex operator+(double d) const;
    Complex operator-(Complex c2) const;
    Complex operator-(double d) const;
    Complex operator/(Complex c2) const;
    Complex operator/(double d) const;
    [[nodiscard]] double abs() const;
    [[nodiscard]] Complex conj() const;
    [[nodiscard]] Complex exp() const;

};
    Complex operator*(double d, Complex c);
    Complex operator+(double d, Complex c);
    Complex operator-(double d, Complex c);
    Complex operator/(double d, Complex c);

}  // namespace complex_numbers
