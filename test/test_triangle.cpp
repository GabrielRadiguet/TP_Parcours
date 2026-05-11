#include <iostream>
#include <cmath>

#include "test.hpp"

#include "../include/point.hpp"
#include "../include/shapes/circle.hpp"
#include "../include/shapes/triangle.hpp"


struct Triangle {
	Point A,B,C;
	
	Triangle(Point P, Point Q, Point R);
	
	double perimeter();
	
	double area();
	
	Point center(); // computes the center of gravity of the triangle
	
	void draw();
	
	void translate(Point T);
	
	void resize(double ratio); // resize while maintaining center
	
	void rotate(double angle); // rotate counterclockwise around the center of the triangle 
	
	bool equals(Triangle triangle);
	
	bool isRightAngled();
	
	bool isEquilateral();
	
	bool isIsoceles();
	
	Circle inscribedCircle();
	
	Circle circumscribedCircle();
};


void test_triangle() {
    std::cout << "--- Debut Tests Triangle ---" << std::endl;

    Triangle t(Point(0, 0), Point(1, 0), Point(0, 1));
    ASSERT(t.equals(t));
    ASSERT(t.perimeter() == 2 + std::sqrt(2));
    ASSERT(t.area() == 0.5);
    ASSERT(t.center().equals(Point(1.0/3, 1.0/3)));

    Triangle t2(Point(-1.0/3, -1.0/3), Point(2 - 1.0/3, -1.0/3), Point(-1.0/3, 2 - 1.0/3));
    ASSERT(t.perimeter() == 4 + std::sqrt(8));
    ASSERT(t.area() == 2);
    ASSERT(t.center().equals(Point(1.0/3, 1.0/3)));

    ASSERT(!t.equals(t2));
    t.resize(2);
    ASSERT(t.equals(t2));

    Triangle t3(Point(0, 0), Point(1, 0), Point(0, 1));
    Triangle t4(Point(-10, -10), Point(-9, -10), Point(-10, -9));
    Triangle t5(Point(1, 1), Point(1, 0), Point(0, 1));

    ASSERT(!t5.equals(t3));
    t5.rotate(M_PI); // rotation de pi
    ASSERT(t5.equals(t3));

    ASSERT(!t3.equals(t4));
    t3.translate(Point(-10, -10));
    ASSERT(t3.equals(t4));

    
    ASSERT(t3.isRightAngled());

    Triangle t6(Point(-1,-1), Point(1, 0), Point(0, 1));
    ASSERT(!t6.isRightAngled());
    ASSERT(t6.isEquilateral());


    Triangle t7(Point(0,0), Point(1, 0), Point(0.5, sqrt(3)/2));
    ASSERT(t7.isEquilateral());
    ASSERT(t7.isIsoceles());

    Circle incircle = t7.inscribedCircle();
    ASSERT(incircle.equals(Circle(2.0/3, Point(0.5, 1.0/3))));

    Circle circircle = t7.circumscribedCircle();
    ASSERT(circircle.equals(Circle(1.0/3, Point(0.5, 1.0/3))));

    Triangle t8(Point(0, 0), Point(1, 0), Point(0, 1));

    Circle incircle = t8.inscribedCircle();
    ASSERT(incircle.equals(Circle(sqrt(2)/2, Point(1.0/3, 1.0/3))));

    Circle circircle = t8.circumscribedCircle();
    ASSERT(circircle.equals(Circle(1.0/3, Point(0.5, 1.0/3))));

    std::cout << "--- Fin Tests Triangle ---" << std::endl << std::endl;
}