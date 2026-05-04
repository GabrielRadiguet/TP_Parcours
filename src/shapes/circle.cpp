#include "point.hpp"
#include "shapes/circle.hpp"
#include  <cmath>

Circle::Circle(double r, Point c) : radius(r), center(c) {};

double Circle::circumference(){
    return M_PI * radius * 2;
}

double Circle::area(){
    return M_PI * radius * radius;
}

