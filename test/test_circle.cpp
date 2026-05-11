#include <iostream>
#include <cmath>
#include <numbers>

#include "test.hpp"

#include "../include/point.hpp"
#include "../include/shapes/circle.hpp"

void test_circle()
{
    std::cout << "--- Debut Tests Cercle ---" << std::endl;

    Circle c(50, Point(0, 0));
    ASSERT(c.equals(c));

    ASSERT(c.circumference() == 2 * 50 * std::numbers::pi);
    ASSERT(c.area() == 50 * 50 * std::numbers::pi);

    Point p(10,10);
    Circle c2(50, p);
    ASSERT(!c.equals(c2));
    c.translate(p);
    ASSERT(c.equals(c2));

    Circle c3(10, p);
    ASSERT(!c.equals(c3));
    c3.resize(5);
    ASSERT(c3.equals(c));

    c.resize(9);
    ASSERT(c.radius == 9 * 50);

    std::cout << "--- Fin Tests Cercle ---" << std::endl << std::endl;
}