#include "Vector.h"
#include "Direct.h"

Vector::Vector(Point A, Point B) :DirectedLine(A, B) {};

bool Vector::contains_point(const Point& point) const
{
	if (point == m_start || point == m_direction) return true;

	Direct direct(m_start, m_direction);
	if (!direct.contains_point(point)) return false;
	
	Vector from_start_to_end(m_start, m_direction);
	Vector from_start_to_point(m_start, point);
	Vector from_end_to_start(m_direction, m_start);
	Vector from_end_to_point(m_direction, point);

	if (from_start_to_end.codirectional(from_start_to_point) && from_end_to_start.codirectional(from_end_to_point)) return true;
	else return false;

}