#include "complex_numbers.h"


namespace complex_numbers {


Complex::Complex(double real, double imaginary) {
    this->real_part = real;
    this->imaginary_part = imaginary;
}

double Complex::real() const {
    return this->real_part;
}

double Complex::imag() const {
    return this->imaginary_part;
}

Complex Complex::operator*(const Complex c2) const {
    return  {(this->real_part * c2.real_part - this->imaginary_part * c2.imaginary_part),
   (this->imaginary_part * c2.real_part + this->real_part * c2.imaginary_part)};
}

Complex Complex::operator*(double d) const {
    return operator*({d, 0});
}

Complex Complex::operator+(Complex c2) const {
    return {(this->real_part + c2.real_part), (this->imaginary_part + c2.imaginary_part)};
}

Complex Complex::operator+(double d) const {
    return operator+({d, 0});
}

Complex Complex::operator-(Complex c2) const {
    return {(this->real_part - c2.real_part), (this->imaginary_part - c2.imaginary_part)};
}

Complex Complex::operator-(double d) const {
    return operator-({d, 0});
}

Complex Complex::operator/(Complex c2) const {
    double temp_real {(this->real_part * c2.real_part + this->imaginary_part * c2.imaginary_part)
        / (std::__math::pow(c2.real_part, 2) + std::__math::pow(c2.imaginary_part, 2))};
    double temp_imaginary {(this->imaginary_part * c2.real_part - this->real_part * c2.imaginary_part)
            / (std::__math::pow(c2.real_part, 2) + std::__math::pow(c2.imaginary_part, 2))};
    return {temp_real, temp_imaginary};
}

Complex Complex::operator/(double d) const {
    return operator/({d, 0});
}

double Complex::abs() const {
    return std::__math::sqrt(std::__math::pow(this->real_part, 2)
        + std::__math::pow(this->imaginary_part, 2));
}

Complex Complex::conj() const {
    return {this->real_part, this->imaginary_part * -1};
}

Complex Complex::exp() const {
    return std::__math::pow(constant_e, this->real_part)
    * (Complex(std::__math::cos(this->imaginary_part),
        std::__math::sin(this->imaginary_part)));

}

Complex operator*(double d, Complex c) {
    return Complex(d, 0.0) * c;
}

Complex operator+(double d, Complex c) {
    return Complex(d, 0.0) + c;
}

Complex operator-(double d, Complex c) {
    return Complex(d, 0.0) - c;
}

Complex operator/(double d, Complex c) {
    return Complex(d, 0.0) / c;
}
}  // namespace complex_numbers
