// Arda Barak
// 300129340

#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double l = 1.0, double w = 1.0) : length(l), width(w) {} //constructor

    double area() const { //calc area
        return length * width;
    }
    double perimeter() const {  //calc perimeter
        return 2 * (length + width);
    }
    void resize(double newLength, double newWidth) { //resize rectangle
        length = newLength;
        width = newWidth;
    }
    void show() const { //show dimensions
        cout << "Length:    " << length << "\nWidth:     " << width << endl;
    }
};

bool compareArea(Rectangle rect1, Rectangle rect2) {    //compare areas
    return rect1.area() > rect2.area();
}
bool compareAreaConstRef(const Rectangle& rect1, const Rectangle& rect2) { //same as the one above but with const
    return rect1.area() > rect2.area();
}

int main() {
    double length1, length2;
    double width1, width2;
    // Rectangle R1, R2;
    cout << "enter length and width for rectangle 1:    ";
    cin >> length1 >> width1;
    cout << "enter length and width for rectangle 2:    ";
    cin >> length2 >> width2;
    Rectangle R1(length1, width1);
    Rectangle R2(length2, width2);
    
    cout << "Before resizes:   " << endl;
    cout << "R1 :\n"; R1.show();
    cout << "R2 :\n"; R2.show();
    // cout << R1.show();
    // cout << R2.show();
    
    if (compareArea(R1, R2)) {
        cout << "R1 > R2 (without const)" << endl;
    } else {
        cout << "R2 >= R1 (without const)" << endl;
    }
    //resizing
    R1.resize(10.0, 5.0);
    R2.resize(20.0, 30.0);
    // R1.resize(1.0, 2.0);
    // R2.resize(3.0, 4.0);
    cout << "\nAfter resizing (10.00,5.00 and 3.00,4.00):" << endl;
    cout << "R1 :\n"; R1.show();
    cout << "R2 :\n"; R2.show();
    //areas after resizing
    if (compareAreaConstRef(R1, R2)) {
        cout << "R1 > R2 (with const)" << endl;
    } else {
        cout << "R2 >= R1 (with const)" << endl;
    }
    return 0;
}
