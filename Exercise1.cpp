// Arda Barak
// 300129340
// Exercise 1

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class MyString {
private:
    std::string str;

public:
    MyString(const std::string& s = "") : str(s) {} //constructor

    MyString operator+(const MyString& other) const {return MyString(str + other.str);} //overloading +

    bool operator==(const MyString& other) const {return str == other.str;} //overloading ==

    friend std::ostream& operator<<(std::ostream& os, const MyString& myStr) { //overloading <<
        os << myStr.str;
        return os;
    }

    size_t length() const {return str.length();} //getting length of string

    bool operator<(const MyString& other) const {return str < other.str;} //overloading < for alphabetical comparison
};

struct CompareByLength { //functor comparing by length
    bool operator()(const MyString& a, const MyString& b) const {return a.length() < b.length();}
};

int main() {
    //myString objects
    MyString str1("Hello");
    MyString str2("World");
    MyString str3("C++");
    MyString str4("Programming");
    //+ 2 strings
    MyString concatenated = str1 + str2;
    std::cout << "Concatenated String: " << concatenated << "\n";
    //comparing for ==
    std::cout << "Are String1 and String2 equal? " << (str1 == str2 ? "Yes" : "No") << "\n";
    
    //sorting vector of myString objects by length, then alphabetically of equal lengths
    std::vector<MyString> myStrings = {str1, str2, str3, str4};
    std::sort(myStrings.begin(), myStrings.end(), [](const MyString& a, const MyString& b) {
        if (a.length() != b.length()) {return a.length() < b.length();}
        return a < b;
    });
    std::cout << "Strings sorted alphabetically and by length: ";
    for (const auto& s : myStrings) std::cout << s << " ";
    std::cout << "\n";
    return 0;
}