#ifndef POLYGON_H
#define POLYGON_H
#include <vector>
#include <iostream>
#include <math.h>
#include "Point.h"

class Polygon {
public:
    Polygon() : Polygon(std::vector<Point>{}) {}
    Polygon(std::vector<Point> points);
    bool get_vertex(long unsigned int position, Point &save_result);
    bool add_vertex(long unsigned int position, Point new_point);
    double perimeter();
    void show();
private:
    double distance(Point p1, Point p2);
    std::vector<Point> array_vertices;
    int num_vertices;
};

#endif