// Arda Barak
// 300129340
// Exercise 3

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

template <typename From, typename To>   //declaring base template 
struct UnitConverter;

template <>
struct UnitConverter<double, double> {  //specializing convert m->cm
    static double convert(double value, const string& fromUnit, const string& toUnit) {
        if (fromUnit == "m" && toUnit == "cm") {
            return value * 100.0;  //1m     = 100cm
        } else if (fromUnit == "cm" && toUnit == "m") {
            return value / 100.0;  //100cm  = 1m
        } else {
            return value;  //if units are the same
        }
    }
};

template <>
struct UnitConverter<int, int> {    //overloading for integer for int -> int
    static int convert(int value, const string& fromUnit, const string& toUnit) {
        if (fromUnit == "m" && toUnit == "cm") {
            return value * 100;  //1m     = 100cm
        } else if (fromUnit == "cm" && toUnit == "m") {
            return value / 100;  //100cm  = 1m
        } else {
            return value;  //if units are the same
        }
    }
};

template <typename T>
void performConversion() {  //funct for user input and conversion
    T value;
    string fromUnit, toUnit;
    cout << "Enter value to convert:    ";
    cin >> value;
    cout << "Convert From [cm, m]:      ";
    cin >> fromUnit;
    cout << "Convert To [cm, m]:        ";
    cin >> toUnit;
    T result = UnitConverter<T, T>::convert(value, fromUnit, toUnit);   //using UnitConverter struct for conversion
    cout << fixed << setprecision(2);                                   //displaying results with 2 decimal places for floats
    cout << value << " " << fromUnit << " is " << result << " " << toUnit << endl;
}

int main() {
    char choice;
    cout << "Select input type [i for int, f for float]:    ";    //taking input as either integer or double
    cin >> choice;
    if (choice == 'i')          //if int
        {performConversion<int>();} 
    else if (choice == 'f')     //if float
        {performConversion<double>();} 
    else 
        {cout << "Invalid input type " << endl;}
    return 0;
}
