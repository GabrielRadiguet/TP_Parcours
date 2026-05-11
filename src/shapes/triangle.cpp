#include "point.hpp"
#include "shapes/triangle.hpp"
#include "CTurtle.hpp"
#include "shapes/circle.hpp"
#include <vector>
#include <cmath>
#include <draw.hpp>

namespace ct = cturtle;

Triangle::Triangle(Point P, Point Q, Point R) : A(P), B(Q), C(R) {}

double Triangle::perimeter(){
    return A.distance(B) + B.distance(C) + C.distance(A);
}

double Triangle::area(){
    return (1.0/2.0) * abs(A.x*(B.y-C.y) + B.x*(C.y-A.y) + C.x*(A.y-B.y));
}

Point Triangle::center()// computes the center of gravity of the triangle
{
    Point centre = Point((A.x + B.x + C.x) / 3.0, (A.y + B.y + C.y) / 3.0);
    return centre;
}

void Triangle::draw(){
    // définition de l'ordre des points dans un vecteur
    std::vector<Point> dessin = {
        A,
        B,
        C,
        A
    };

    draw_picture(dessin);
}

void Triangle::translate(Point T){
    Point centre = center();
    A.x += T.x;
    A.y += T.y;
    B.x += T.x;
    B.y += T.y;
    C.x += T.x;
    C.y += T.y;
}

void Triangle::resize(double ratio) {
    // resize while maintaining center
    Point centre = center();
    A.x = centre.x + ratio * (A.x - centre.x);
    A.y = centre.y + ratio * (A.y - centre.y);
    B.x = centre.x + ratio * (B.x - centre.x);
    B.y = centre.y + ratio * (B.y - centre.y);
    C.x = centre.x + ratio * (C.x - centre.x);
    C.y = centre.y + ratio * (C.y - centre.y);
}

void Triangle::rotate(double angle) // rotate counterclockwise around the center of the triangle 
{   Point centre = center();
    translate(Point(0,0));
    double dx = A.x;
    double dy = A.y;
    A.x = dx * cos(angle) - dy * sin(angle);
    A.y = dx * sin(angle) + dy * cos(angle);
    dx = B.x;
    dy = B.y;
    B.x = dx * cos(angle) - dy * sin(angle);
    B.y = dx * sin(angle) + dy * cos(angle);
    dx = C.x;
    dy = C.y;
    C.x = dx * cos(angle) - dy * sin(angle);
    C.y = dx * sin(angle) + dy * cos(angle);
    translate(centre);
}

bool Triangle::equals(Triangle triangle){
    if(A.equals(triangle.A) && B.equals(triangle.B) && C.equals(C)){
        return true;
    }
    if(A.equals(triangle.A) && B.equals(triangle.C) && C.equals(B)){
        return true;
    }
    if(A.equals(triangle.B) && B.equals(triangle.A) && C.equals(C)){
        return true;
    }
    if(A.equals(triangle.B) && B.equals(triangle.C) && C.equals(A)){
        return true;
    }
    if(A.equals(triangle.C) && B.equals(triangle.B) && C.equals(A)){
        return true;
    }
    if(A.equals(triangle.C) && B.equals(triangle.A) && C.equals(B)){
        return true;
    }
    return false;
}

bool Triangle::isRightAngled(){
    double ab = A.distance(B);
    double ac = A.distance(C);
    double cb = C.distance(B);
    if(ab > ac && ab > cb){
        if(ab == sqrt(ac * ac + cb * cb)){
            return true;
        }
    }
    if(ac > ab && ac > cb){
        if(ac == sqrt(ab * ab + cb * cb)){
            return true;
        }
    }
    if(cb > ac && cb > ab){
        if(cb == sqrt(ac * ac + ab * ab)){
            return true;
        }
    }
    return false;
}

bool Triangle::isEquilateral(){
    double ab = A.distance(B);
    double ac = A.distance(C);
    double cb = C.distance(B);
    if(ab == ac && ab == cb){
        return true;
    }
    return false;
}

bool Triangle::isIsoceles(){
    double ab = A.distance(B);
    double ac = A.distance(C);
    double cb = C.distance(B);
    if(ab == ac || ab == cb || ac == cb){
        return true;
    }
    return false;
}

Circle Triangle::inscribedCircle(){
    return Circle((2.0 * area())/perimeter(), center());
}

Circle Triangle::circumscribedCircle(){
    double ab = A.distance(B);
    double ac = A.distance(C);
    double cb = C.distance(B);
    return Circle((ab + ac + cb)/4.0 * area(), center());
}