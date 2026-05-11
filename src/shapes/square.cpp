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

void Square::resize(double ratio){
	Point c = center();
    std::vector<double> v1 ={ratio * (c.x - A.x) ,ratio * (c.y - A.y) };
    C = Point(c.x + v1.at(0) , c.y + v1.at(1));
    A = Point(c.x - v1.at(0) , c.y - v1.at(1) ) ;
    

}

void Square::rotate(double angle){
	Point c = center();
    std::vector<double> v1 ={ cos(angle) * (c.x - A.x) - sin(angle) * (c.y - A.y) , sin(angle) * (c.x - A.x) + cos(angle) *(c.y - A.y) };
    C = Point(c.x + v1.at(0) , c.y + v1.at(1));
    A = Point(c.x - v1.at(0) , c.y - v1.at(1) );
}

bool Square::equals(Square square){
	if ( A.x == square.A.x and A.y == square.A.y and C.x == square.C.x and C.y == square.C.y ){
		return true;
	}
	else{
		 return false;
		 }

}