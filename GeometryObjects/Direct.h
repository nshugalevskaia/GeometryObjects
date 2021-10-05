#pragma once
#include <tuple>
#include "Point.h"
#include "Line.h"
class Direct final:public Line
{
public:
	
	Direct() = delete;
	Direct(const Direct&) = default;
	Direct(double a, double b, double c);
	Direct(Point A, Point B);

	std::tuple<double, double, double> get_line_coeff() const override;
	bool contains_point(const Point& point) const override;

private:
	double m_a;
	double m_b;
	double m_c;
};



