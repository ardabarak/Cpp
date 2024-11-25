// Arda Barak
// 300129340
// Exercise 1

#include <iostream>

class Date {
private:
    int day, month, year;
public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {} //date
    void operator+(int n) {day += n;}                        //+ operator
    void operator-(int n) {day -= n;}                        //- operator
    //= operator
    bool operator==(const Date& other) const {return year == other.year && month == other.month && day == other.day;}
    //< operator
    bool operator<(const Date& other) const {return year < other.year || (year == other.year && month < other.month) || (year == other.year && month == other.month && day < other.day);}
    //> operator
    bool operator>(const Date& other) const {return year > other.year || (year == other.year && month > other.month) || (year == other.year && month == other.month && day > other.day);}
    void print() const {std::cout << day << "/" << month << "/" << year << std::endl;}
};

int main() {
    Date date1(15, 5, 2023);
    Date date2(24, 6, 2024);
    Date date3(31, 5, 2023);
    Date date4(30, 5, 2023);
    Date date5(20, 3, 2023);
    date1.print();
    date2.print();
    date3.print();
    date4.print();
    date5.print();
    date1 + 5;
    date2 - 2;
    date1.print();
    date2.print();
    std::cout << "is first date earlier than second : " << std::boolalpha << (date1 < date2) << std::endl;
    std::cout << "is first date earlier than third  : " << std::boolalpha << (date1 < date3) << std::endl;
    std::cout << "is second date later than third   : " << std::boolalpha << (date2 > date4) << std::endl;
    std::cout << "is thirs date the same as fourth  : " << std::boolalpha << (date3 == date4) << std::endl;
    return 0;
}
