#include "HalfLine.h"
#include "Direct.h"

HalfLine::HalfLine(Point A, Point D):DirectedLine(A, D) {};

bool HalfLine::contains_point(const Point& point) const
{
	if (point == m_start) return true;
	Direct direct(m_start, m_direction);
	HalfLine direction_to_point(m_start, point);
	if (direct.contains_point(point) && this->codirectional(direction_to_point)) return true;
	else return false;
}

