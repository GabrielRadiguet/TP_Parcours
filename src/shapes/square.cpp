#include "draw.hpp"
#include "point.hpp"
#include "shapes.hpp"
#include "shapes/square.hpp"
#include <vector>

Square::Square(Point P, Point Q) : A(P),C(Q){}

void Square::draw() {
	
	// Define points in a vector
	std::vector<Point> points = {
		A,
		Point(C.x, A.y),
		C,
		Point(A.x, C.y),
		A
		
	};
	
	// Draw the picture by connecting the points
	draw_picture(points);
	
}
double Square::side(){
	double s = C.x - A.x;
	if(s<0){s=-s;};
	return s; 
}
double Square::perimeter(){
	return 4 * side();
}