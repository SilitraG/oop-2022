#include "complex.h"

Complex::Complex() : Complex(0, 0) {}

Complex::Complex(double real, double imag) {
    real_data = real;
    imag_data = imag;
}

bool Complex::is_real() const {
    return imag() == 0;
}

double Complex::real() const {
    return real_data;
}

double Complex::imag() const {
    return imag_data;
}

double Complex::abs() const {
    return sqrt(real() * real() + imag() * imag());
}

Complex Complex::conjugate() const {
    return { real(), -imag() };
}

Complex& Complex::operator()(double real, double imag)
{
    real_data = real;
    imag_data = imag;
    return *this;
}

Complex& Complex::operator++()
{
    real_data++;
    return *this;
}

Complex Complex::operator++(int)
{
    const Complex copy = *this;
    ++(*this);
    return copy;
}

Complex& Complex::operator--()
{
    real_data--;
    return *this;
}

Complex Complex::operator--(int)
{
    const Complex copy = *this;
    --(*this);
    return copy;
}

Complex operator+(const Complex& l, const Complex& r)
{
    double real = l.real() + r.real();
    double imaginar = l.imag() + r.imag(); ///asa
    Complex numar(real, imaginar);
    return numar;
}

Complex operator+(const Complex& l, double r)
{
    Complex copy(r, 0);
    return copy + l;
}

Complex operator+(double l, const Complex& r)
{
    Complex copy(l, 0);
    return copy + r;
}

Complex operator-(const Complex& l, const Complex& r)
{
    return { l.real() - r.real(), l.imag() - r.imag() }; ///sau asa
}

Complex operator-(const Complex& l, double r)
{
    return l - Complex(r,0);
}

Complex operator-(double l, const Complex& r)
{
    return Complex(l, 0) - r;
}

Complex operator*(const Complex& l, const Complex& r)
{
    return {l.real() * r.real() - l.imag() * r.imag(),  l.real() * r.imag() + r.real() * l.imag() };
}

Complex operator*(const Complex& l, double r)
{
    return l * Complex(r, 0);
}

Complex operator*(double l, const Complex& r)
{
    return Complex(l, 0) * r;
}

Complex operator-(const Complex& obj)
{
    return { -obj.real(), -obj.imag() };
}

bool operator==(const Complex& l, const Complex& r)
{
    return l.real() == r.real() && l.imag() == r.imag();
}

bool operator!=(const Complex& l, const Complex& r)
{
    return !(l == r);
}

std::ostream& operator<<(std::ostream& out, const Complex& complex)
{
    // TODO: insert return statement here
    out << complex.real() << " " << complex.imag() << "i\n";
    return out;
}
