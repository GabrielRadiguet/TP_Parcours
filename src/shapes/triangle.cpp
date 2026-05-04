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
    return (1/2) * abs(A.x*(B.y-C.y) + B.x*(C.y-A.y) + C.x*(A.y-B.y));
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