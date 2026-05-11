#include "point.hpp"
#include "shapes/circle.hpp"
#include "draw.hpp"
#include  <cmath>
#include <vector>


Circle::Circle(double r, Point c) : radius(r), center(c) {};

double Circle::circumference(){
    return M_PI * radius * 2;
}

double Circle::area(){
    return M_PI * radius * radius;
}

void Circle::draw(){
    std::vector<Point> liste; 
    int nSeg = 36; //Nombre de segment de cercle
    double angle;
    Point p;
    for (int i=0; i<nSeg; i++){
        angle = 2 * M_PI * i / nSeg;
        p.x = cos(angle)*radius + center.x;
        p.y = sin(angle)*radius + center.y;
        liste.push_back(p);
    }
    angle = 0;
    p.x = cos(angle)*radius + center.x;
    p.y = sin(angle)*radius + center.y;
    liste.push_back(p);
    draw_picture(liste);
}

void Circle::translate(Point T){
    center.x += T.x;
    center.y += T.y;
    std::vector<Point> liste; 
    int nSeg = 36; //Nombre de segment de cercle
    double angle;
    Point p;
    for (int i=0; i<nSeg; i++){
        angle = 2 * M_PI * i / nSeg;
        p.x = cos(angle)*radius + center.x;
        p.y = sin(angle)*radius + center.y;
        liste.push_back(p);
    }
    angle = 0;
    p.x = cos(angle)*radius + center.x;
    p.y = sin(angle)*radius + center.y;
    liste.push_back(p);
    draw_picture(liste);
}

void Circle::resize(double ratio){
    radius *= ratio;
    std::vector<Point> liste; 
    int nSeg = 36; //Nombre de segment de cercle
    double angle;
    Point p;
    for (int i=0; i<nSeg; i++){
        angle = 2 * M_PI * i / nSeg;
        p.x = cos(angle)*radius + center.x;
        p.y = sin(angle)*radius + center.y;
        liste.push_back(p);
    }
    angle = 0;
    p.x = cos(angle)*radius + center.x;
    p.y = sin(angle)*radius + center.y;
    liste.push_back(p);
    draw_picture(liste);
}

bool Circle::equals(Circle circle){
    if (center.x == circle.center.x && center.y == circle.center.y && radius == circle.radius)
        return true;
    return false;
}