#include <iostream>
#include <cmath>
#include <stdexcept>

class ComplexNumber
{
public:
    ComplexNumber() : real(0), imaginary(0) {}
    ComplexNumber(double r, double i) : real(r), imaginary(i) {}
    // ComplexNumber(const ComplexNumber &other) : real(other.real), imaginary(other.imaginary) {}

    // ComplexNumber &operator=(const ComplexNumber &other)
    // {
    //     if (this != &other)
    //     {
    //         real = other.real;
    //         imaginary = other.imaginary;
    //     }
    //     return *this;
    // }

    ComplexNumber operator+(const ComplexNumber &other) const
    {
        return ComplexNumber(real + other.real, imaginary + other.imaginary);
    }

    ComplexNumber operator-(const ComplexNumber &other) const
    {
        return ComplexNumber(real - other.real, imaginary - other.imaginary);
    }

    ComplexNumber operator*(const ComplexNumber &other) const
    {
        // a+bi , c+di.......a*c-b*d+a*di+c*bi
        return ComplexNumber(real * other.real - imaginary * other.imaginary, real * other.imaginary + other.real * imaginary);
    }

    ComplexNumber operator/(const ComplexNumber &other) const
    {
        double denom = other.real * other.real + other.imaginary * other.imaginary;
        if (denom == 0)
            throw std::runtime_error("Division by zero.");
        // std::cout<<denom<<std::endl;
        double realVal = (real * other.real + imaginary * other.imaginary) / denom;
        // std::cout<<realVal<<std::endl;
        double imagVal = (imaginary * other.real - real * other.imaginary) / denom;
        // std::cout<<imagVal<<std::endl;
        return ComplexNumber(realVal, imagVal);
    }

    void printNum() const
    {
        std::cout << real << (imaginary < 0 ? " - " : " + ") << std::abs(imaginary) << "i\n";
    }

    double magnitude() const
    {
        return std::sqrt((real * real) + (imaginary * imaginary));
    }

private:
    double real, imaginary;
};

int main()
{
    ComplexNumber a(3, 4);
    ComplexNumber b(2, 3);
    ComplexNumber c = a - b;
    c.printNum();
    c = a / b;
    c.printNum();
    return 0;
}