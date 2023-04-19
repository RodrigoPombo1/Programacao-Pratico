#ifndef POINT_H
#define POINT_H
#include <iostream>

class Point {
public:
    Point() : x(0), y(0) {}
    Point(int x, int y);
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    void show();
private:
    int x;
    int y;
};

#endif