#ifndef POINT_HPP
#define POINT_HPP

struct Point {
	double x, y;

	Point(double x_val = 0, double y_val = 0);
	
	double distance(Point B = Point());

	bool equals(Point B = Point());
};

bool comp_double(double a, double b, double epsilon = 1e-9);

#endif // POINT_HPP