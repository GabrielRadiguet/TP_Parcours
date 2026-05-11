#include <iostream>
#include <cmath>

#include "test.hpp"

#include "../include/point.hpp"
#include "../include/shapes/circle.hpp"
#include "../include/shapes/square.hpp"

void test_square() {
    std::cout << "--- Debut Tests Carre ---" << std::endl;

    Square s(Point(0, 0), Point(1, 1));
    ASSERT(s.equals(s));
    ASSERT(s.side() == 1);
    ASSERT(s.perimeter() == 4);
    ASSERT(s.area() == 1);
    ASSERT(s.center().equals(Point(0.5, 0.5)));

    Square s2(Point(0.5, (sqrt(2)/2) - 0.5), Point((sqrt(2)/2) + 0.5, 0.5));
    ASSERT(!s2.equals(s));
    ASSERT(s2.side() == 1);
    ASSERT(s2.perimeter() == 4);
    ASSERT(s2.area() == 1);
    ASSERT(s2.center().equals(s.center()));

    Square s3(Point(0, 0), Point(1, 1));
    ASSERT(s.equals(s3));

    Square s4(Point(-1, -1), Point(2, 2));
    s3.resize(3);
    ASSERT(s3.equals(s4));

    s.rotate(M_PI_4); // rotation pi/4
    ASSERT(s.equals(s2));

    Square s(Point(1,1), Point(2, 2));
    s4.translate(Point(-5,10));
    ASSERT(s.equals(Square(Point(-4, 11), Point(-3, 12))));

    s.resize(2);
    ASSERT(s.equals(Square(Point(-3.5, 10.5), Point(-3.5, 12.5))));

    std::cout << "--- Fin Tests Carre ---" << std::endl << std::endl;
}