#include "draw.hpp"
#include "point.hpp"
#include "shapes.hpp"
#include "shapes/square.hpp"
#include <vector>

Square::Square(Point P, Point Q) : A(P),C(Q){}

double Square::side(){
	  
	return sqrt(A.distance(B) * A.distance(B) )/2 ); 
}

void Square::draw() {
	
	// Define points in a vector
	std::vector<Point> points = {
		A,
		Point(A.x, A.y),
		C,
		Point(A.x, C.y),
		A
		
	};
	// Draw the picture by connecting the points
	draw_picture(points);
	
}


double Square::perimeter(){
	return 4 * side();
}

double Square::area(){
	return side()*side();
}

Point Square::center(){
	return Point( (A.x+C.x)/2 , (A.y+C.y)/2 ) ;

}