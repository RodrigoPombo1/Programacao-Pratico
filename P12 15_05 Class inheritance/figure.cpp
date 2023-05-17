#include "Figure.h"
#include <iostream>
#include <vector>
using namespace std;

class Rectangle : public Figure {
public:
    Rectangle(double x_center, double y_center, double width, double height) : Figure(x_center, y_center), width_(width), height_(height) {}
    void draw() const {
        cout << "R(" << x_center_ << ',' << y_center_ << ")(" << width_ << ',' << height_ << ')';
    }
private:
    double width_;
    double height_;
};

class Circle : public Figure {
public:
    Circle(double x_center, double y_center, double radius) : Figure(x_center, y_center), radius_(radius) {}
    void draw() const {
        cout << "C(" << x_center_ << ',' << y_center_ << ")(" << radius_ << ')';
    }
private:
    double radius_;
};


int main() {
    { Rectangle r(10, 10, 200, 100);
  r.draw(); cout << endl; }
    return 0;
}