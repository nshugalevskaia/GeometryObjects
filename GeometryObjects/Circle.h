#pragma once
 
#include "Point.h"
class Circle final {

public:
	Circle() = delete;
	Circle(const Circle&) = default;
	Circle(const Point& center, double R);

	bool contains_inside(const Point& point);

	const Point m_center;
	const double m_radius;
};