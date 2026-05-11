#include <iostream>
#include <cmath>
#include <numbers>

#include "test.hpp"

#include "../include/point.hpp"
#include "../include/shapes/circle.hpp"
#include "../include/shapes/triangle.hpp"

void test_triangle() {
    std::cout << "--- Debut Tests Triangle ---" << std::endl;

    Triangle t(Point(0.0, 0.0), Point(1.0, 0.0), Point(0.0, 1.0));
    ASSERT(t.equals(t));
    ASSERT(t.perimeter() == 2 + std::sqrt(2));
    ASSERT(t.area() == 0.5);
    ASSERT(t.center().equals(Point(1.0/3, 1.0/3)));

    Triangle t2(Point(-1.0, -1.0), Point(3.0, -1.0), Point(-1.0, 3.0));
    ASSERT(t2.perimeter() == 8 + std::sqrt(32));
    ASSERT(t2.area() == 8);
    ASSERT(t2.center().equals(Point(1.0/3, 1.0/3)));

    ASSERT(!t.equals(t2));
    t.resize(4.0);
    ASSERT(t.equals(t2));

    Triangle t3(Point(0.0, 0.0), Point(1.0, 0.0), Point(0.0, 1.0));
    Triangle t4(Point(-10.0, -10.0), Point(-9.0, -10.0), Point(-10.0, -9.0));
    Triangle t5(Point(2.0/3, 2.0/3), Point(-1.0/3, 2.0/3), Point(2.0/3, -1.0/3));
    
    ASSERT(!t5.equals(t3));
    t5.rotate(std::numbers::pi); // rotation de pi
    
    ASSERT(t5.equals(t3));

    ASSERT(!t3.equals(t4));
    t3.translate(Point(-10.0, -10.0));
    ASSERT(t3.equals(t4));

    
    ASSERT(t3.isRightAngled());

    Triangle t6(Point(-1.0, -1.0), Point(1.0, 0.0), Point(0.0, 1.0));
    ASSERT(!t6.isRightAngled());
    ASSERT(t6.isIsoceles());


    Triangle t7(Point(0.0, 0.0), Point(1.0, 0.0), Point(0.5, std::sqrt(3)/2));
    ASSERT(t7.isEquilateral());
    ASSERT(t7.isIsoceles());

    Circle incircle = t7.inscribedCircle();
    ASSERT(incircle.equals(Circle(std::sqrt(3)/6, Point(0.5, std::sqrt(3)/6))));

    Circle circircle = t7.circumscribedCircle();
    ASSERT(circircle.equals(Circle(std::sqrt(3)/3, Point(0.5, std::sqrt(3)/6))));

    Triangle t8(Point(0.0, 0.0), Point(1.0, 0.0), Point(0.0, 1.0));

    Circle incircle2 = t8.inscribedCircle();
    ASSERT(incircle2.equals(Circle(1.0/(2+std::sqrt(2)), Point(1.0/(2+std::sqrt(2)), 1.0/(2+std::sqrt(2))))));

    Circle circircle2 = t8.circumscribedCircle();
    ASSERT(circircle2.equals(Circle(std::sqrt(2)/2, Point(0.5, 0.5))));

    std::cout << "--- Fin Tests Triangle ---" << std::endl << std::endl;
}