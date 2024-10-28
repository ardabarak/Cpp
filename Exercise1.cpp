// Arda Barak
// 300129340

#include <iostream>
#include <cmath>
#include <stdexcept>
#include <iomanip>

class MathLibrary {
public:
    static inline double squareRoot(double numInp) {//static sqqrt
        if (numInp < 0) {
            throw std::invalid_argument("Error:Negative input provided.");
        }return std::sqrt(numInp);
    }

    static inline double logarithm(double numInp) {//static log
        if (numInp <= 0) {
            throw std::invalid_argument("Error:Negative input provided.");
        }return std::log(numInp);
    }
};

int main() {
    double numInp;
    
    try { //sqrt
        std::cout << "Enter a number to calc its square root:   ";
        std::cin >> numInp;
        std::cout << "Square root of " << numInp << " is " << MathLibrary::squareRoot(numInp) << std::endl;
    }catch (const std::invalid_argument& e) {
        std::cout << "Error:    " << e.what() << std::endl;
    }
    try { //log
        std::cout << "Enter a number to calc its log:           ";
        std::cin >> numInp;
        std::cout << "Logarithm of " << numInp << " is " << MathLibrary::logarithm(numInp) << std::endl;
    }catch (const std::invalid_argument& e) {
        std::cout << "Error:    " << e.what() << std::endl;
    }
    return 0;
}
