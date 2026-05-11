#ifndef DRAW_HPP
#define DRAW_HPP

#include "point.hpp"
#include <vector>

void draw_picture(const std::vector<Point>& points);
void draw_circle(const double r, Point c);

#endif // DRAW_HPP