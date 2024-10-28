// Arda Barak
// 300129340

#include <iostream>
#include <cmath>
#include <string>
// #include <corecrt_math_defines.h>

class Shape {
public:
    virtual void draw() const = 0;
    virtual double area() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}//constr

    void draw() const override {//drawing
        std::cout << "Drawing a circle with r=" << radius << std::endl;
    }
    double area() const override {//area with pi
        return M_PI * radius * radius;
    }
    void setRadius(double newR) {//setting new radius
        radius = newR;
    }
    double getRadius() const {//getting radius
        return radius;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}//constr

    void draw() const override {//draw
        std::cout << "Drawing a rectangle with width=" << width << " and height=" << height << std::endl;
    }

    double area() const override {//area
        return width * height;
    }
};

void updateRadius(Shape* shape, double newRadius) {//updating the radius
    Circle* circle = dynamic_cast<Circle*>(shape);
    if (circle) {
        std::cout << "Updating r of the circle of=" << circle->getRadius() << ", to r=" << newRadius << std::endl;
        circle->setRadius(newRadius);
    } 
    else {
        std::cout << "This shape isnt circle, cant modify" << std::endl;
    }
}

int main() {
    int input;
    std::cout << "Choose a shape to create:\n     1. Circle\n     2. Rectangle\nEnter input as [1] or [2]:     "; //taking user input
    std::cin >> input;
    Shape* newshape = nullptr;
    if (input == 1) {//if circle
        double radius;
        std::cout << "Enter the radius of circle                : ";
        std::cin >> radius;
        newshape = new Circle(radius);
    }
    else if (input == 2) {//if rectangle
        double width, height;
        std::cout << "Enter the width and height of rectangle   : ";
        std::cin >> width >> height;
        newshape = new Rectangle(width, height);
    }
    else {//if neither
        std::cout << "Invalid input." << std::endl;
        return 0;
    }
    newshape->draw();
    std::cout << "Area of shape         :               " << newshape->area() << std::endl;
    if (Circle* circle = dynamic_cast<Circle*>(newshape)) {
        double newRadius;
        std::cout << "Enter a new radius for the circle         : ";
        std::cin >> newRadius;
        updateRadius(newshape, newRadius);
        circle->draw();
        std::cout << "Updated area of circle        : " << circle->area() << std::endl;
    }
    else {
        std::cout << "The shape is a rectangle, No radius modification needed   " << std::endl;
    }
    delete newshape; 
    return 0;
}