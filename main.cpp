#include "draw.hpp"
#include "point.hpp"
#include "shapes.hpp"
#include <vector>
#include "test/test.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

int main() {
	test();
	
	// Define points in a vector
	std::vector<Point> points = {
		Point(0, 0),
		Point(100, 0),
		Point(100, 100),
		Point(0, 100),
		Point(0, 0)
		
	};
	
	// Draw the picture by connecting the points
	draw_picture(points);

	Point centre = {0, 0};
	//draw_circle(15, centre);
	return 0;
}
