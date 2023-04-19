#include "Point.h"
#include "Polygon.h"
using namespace std;

Polygon::Polygon(vector<Point> points) {
    if (points.size() == 0) {
        return;
    }
    this->array_vertices = points;
}

bool Polygon::get_vertex(long unsigned int position, Point &save_result) {
    if (position < 1 || position > array_vertices.size()) {
        return false;
    }
    save_result = array_vertices[position - 1];
    return true;
}

bool Polygon::add_vertex(long unsigned int position, Point new_point) {
    if (position < 0 || position > array_vertices.size()) {
        return false;
    }
    array_vertices.emplace(array_vertices.begin() + position - 1, new_point);
    return true;
}

double Polygon::distance(Point p1, Point p2) {
    return sqrt((double)(pow(p1.getX() - p2.getX(), 2) + pow(p1.getY() - p2.getY(), 2)));
}

double Polygon::perimeter() {
    double result = 0;
    for (long unsigned int i = 0; i < array_vertices.size() - 1; i++) {
        result += distance(array_vertices[i], array_vertices[i + 1]);
    }
    result += distance(array_vertices[array_vertices.size() - 1], array_vertices[0]);
    return result;
}

void Polygon::show() {
    cout << '{';
    for (long unsigned int i = 0; i < array_vertices.size(); i++) {
        array_vertices[i].show();
    }
    cout << '}';
}