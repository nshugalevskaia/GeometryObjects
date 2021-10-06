#include "Point.h"
#include "Constants.h"

double Point::distance_between(Point A, Point B)
{
	auto [x1, x2] = A.get_cartesian_coords();
	auto [y1, y2] = B.get_cartesian_coords();
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

Point::Point(const double x_in, const double y_in): x(x_in),y(y_in)
{}

std::pair<double, double> Point::get_cartesian_coords() const
{
	return { x,y };
}

std::pair<double, double> Point::get_polar_coords() const
{
	double ro = x * x + y * y;
	double fi = atan2(y,x);
	return { ro, fi };
}
double Point::distance_to(const Point& other_point) const
{
	return distance_between(*this, other_point);
}

bool Point::operator==(const Point& other_point) const
{
	if (fabs(x - other_point.x)<precision && fabs(y - other_point.y) < precision) return true;
	else return false;
}

bool Point::operator!=(const Point& other_point) const
{
	return !(*this == other_point);
}