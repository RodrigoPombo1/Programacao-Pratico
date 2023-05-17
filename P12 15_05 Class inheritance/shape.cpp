#include "Shape.h"
#include <cmath>
#include <iostream>
using namespace std;

class Circle : public Shape {
public:
    Circle(const point& center, double radius) : Shape(center), radius_(radius) {}
    double area() const {
        return radius_ * radius_ * M_PI;
    }
    double perimeter() const {
        return radius_ * 2 * M_PI;
    }
    bool contains(const point& point) const {
        double distanceSquared = pow(point.x - get_center().x, 2) + pow(point.y - get_center().y, 2);
        double radiusSquared = pow(radius_, 2);
        return distanceSquared <= radiusSquared;
    }
private:
    double radius_;
};

class Rectangle : public Shape {
public:
    Rectangle(const point& center, double width, double height) : Shape(center), width_(width), height_(height) {}
    double area() const {
        return height_ * width_;
    }
    double perimeter() const {
        return 2 * height_ + 2 * width_;
    }
    bool contains(const point& point) const {
        double halfWidth = width_ / 2.0;
        double halfHeight = height_ / 2.0;

        double left = get_center().x - halfWidth;
        double right = get_center().x + halfWidth;
        double top = get_center().y + halfHeight;
        double bottom = get_center().y - halfHeight;

        return point.x >= left && point.x <= right && point.y >= bottom && point.y <= top;
    }
private:
    double width_;
    double height_;
};

int main() {
    { Circle c({1.0, 2.0}, 1.0); 
  const point& p = c.get_center();
  cout << fixed << setprecision(2) 
       << '(' << p.x << ',' << p.y << ')' << ' '
       << c.area() << ' ' << c.perimeter() << '\n'; }
       { Rectangle r({3.4, 4.5}, 1, 2); 
  const point& p = r.get_center();
  cout << fixed << setprecision(2) 
       << '(' << p.x << ',' << p.y << ')' << ' '
       << r.area() << ' ' << r.perimeter() << '\n'; }
    return 0;
}