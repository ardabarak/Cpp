// Arda Barak
// 300129340
// Exercise 4

#include <iostream>
#include <stdexcept>

class Complex {
private:
    double real, imaginary;

public:
    Complex(double r = 0, double i = 0) : real(r), imaginary(i) {}
    //toplama
    Complex operator+(const Complex& other) const {return Complex(this->real + other.real, this->imaginary + other.imaginary);}
    //cikarma
    Complex operator-(const Complex& other) const {return Complex(this->real - other.real, this->imaginary - other.imaginary);}
    //carpma
    Complex operator*(const Complex& other) const {return Complex(this->real * other.real - this->imaginary * other.imaginary,this->real * other.imaginary + this->imaginary * other.real);}

    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imaginary * other.imaginary;
        if (denominator == 0) {throw std::runtime_error("Dividing by 0");}
        return Complex((this->real * other.real + this->imaginary * other.imaginary) / denominator,(this->imaginary * other.real - this->real * other.imaginary) / denominator);
    }

    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.real << "  +  " << c.imaginary << "i";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Complex& c) {
        std::cout << "Enter real part: ";
        is >> c.real;
        std::cout << "Enter imaginary part: ";
        is >> c.imaginary;
        return is;
    }
};

int main() {
    Complex c1, c2, result;
    std::cout << "Enter first complex number;   \n";
    std::cin >> c1;
    std::cout << "Enter second complex number;  \n";
    std::cin >> c2;
    result = c1 + c2;
    std::cout << "Sum: " << result << std::endl;
    result = c1 - c2;
    std::cout << "Difference: " << result << std::endl;
    result = c1 * c2;
    std::cout << "Multiplication: " << result << std::endl;
    try {
        result = c1 / c2;
        std::cout << "Quotient: " << result << std::endl;
    } catch (const std::runtime_error& e) {std::cout << e.what() << std::endl;}
    return 0;
}
