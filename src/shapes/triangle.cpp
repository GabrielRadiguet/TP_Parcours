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

double Triangle::area(){ //formule de Heron
    double a = A.distance(B);
    double b = B.distance(C);
    double c = C.distance(A);
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
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
{   
    Point centre = center();
    translate(Point(centre.x * -1, centre.y * -1));
    A.x = A.x * cos(angle) - A.y * sin(angle);
    A.y = A.x * sin(angle) + A.y * cos(angle);
    B.x = B.x * cos(angle) - B.y * sin(angle);
    B.y = B.x * sin(angle) + B.y * cos(angle);
    C.x = C.x * cos(angle) - C.y * sin(angle);
    C.y = C.x * sin(angle) + C.y * cos(angle);
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
    double a = A.distance(B);
    double b = B.distance(C);
    double c = C.distance(A);

    //https://en.wikipedia.org/wiki/Incenter#Cartesian_coordinates
    double x = (a * A.x + b * B.x + c * C.x) / (a + b + c);
    double y = (a * A.y + b * B.y + c * C.y) / (a + b + c);
    return Circle((2.0 * area())/perimeter(), Point(x, y));
}

Circle Triangle::circumscribedCircle(){
    double ab = A.distance(B);
    double ac = A.distance(C);
    double cb = C.distance(B);

    // https://en.wikipedia.org/wiki/Circumcircle#Cartesian_coordinates_2
    double D = 2 * (A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));
    double Ux = ((A.x * A.x + A.y * A.y) * (B.y - C.y) + (B.x * B.x + B.y * B.y) * (C.y - A.y) + (C.x * C.x + C.y * C.y) * (A.y - B.y)) / D;
    double Uy = ((A.x * A.x + A.y * A.y) * (C.x - B.x) + (B.x * B.x + B.y * B.y) * (A.x - C.x) + (C.x * C.x + C.y * C.y) * (B.x - A.x)) / D;
    return Circle((ab * ac * cb)/(4.0 * area()), Point(Ux, Uy));
}