#include "Point.h"
#include "Direct.h"
#include<tuple>


Direct::Direct(double a, double b, double c):m_a(a),m_b(b),m_c(c){}

Direct::Direct(Point A, Point B) 
{
	auto [x1,y1] = A.get_cartesian_coords();
	auto [x2, y2] = B.get_cartesian_coords();
    m_a = y2 - y1;
	m_b = -x2 + x1;
	m_c = -x1 * (y2 - y1) + y1 * (x2 - x1);

}

bool Direct::contains_point(const Point& point) const
{
		if (m_a * point.x + m_b * point.y + m_c == 0) return true;
	else return false;
}

std::tuple<double, double, double> Direct::get_line_coeff() const
{
	return {m_a,m_b,m_c};
}
