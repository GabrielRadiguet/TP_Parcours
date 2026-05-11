#include "draw.hpp"
#include "point.hpp"
#include "shapes.hpp"
#include "shapes/square.hpp"
#include <vector>
#include <cmath>

Square::Square(Point P, Point Q) : A(P),C(Q){}


double Square::side(){
	  
	return sqrt((A.distance(C) * A.distance(C) )/2 ); 
}

void Square::draw() {
	Point c = center();
	std::vector<double> v1 ={-(c.y - A.y) , c.x - A.x };
	


	// Define points in a vector
	std::vector<Point> points = {
		A,
		Point(c.x + v1.at(0) , c.y + v1.at(1) ) ,
		C,
		Point(c.x - v1.at(0) , c.y - v1.at(1) ) ,
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