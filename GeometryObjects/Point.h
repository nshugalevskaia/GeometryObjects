
#pragma once
#include <iostream>

class Point
{

public:

	static double distance_between(const Point A, const Point B);
	Point() = default;
	Point(const double x_in, const double y_in);
	std::pair<double, double> get_polar_coords() const;
	std::pair<double, double> get_cartesian_coords() const;
	double distance_to(const Point& other_point) const;
	bool operator==(const Point& other_point) const;
	bool operator!=(const Point& other_point) const;
	const double x = 0;
	const double y = 0;

};
