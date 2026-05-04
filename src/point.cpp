#include "point.hpp"
#include <cmath>


Point::Point(double x_val, double y_val) : x(x_val), y(y_val) {}

double Point::distance(Point B) {
    double dx = x - B.x;
    double dy = y - B.y;
    return sqrt(dx * dx + dy * dy);
}