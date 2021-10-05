#include "Vector.h"
#include "Direct.h"

Vector::Vector(Point A, Point B) :DirectedLine(A, B) {};

bool Vector::contains_point(const Point& point) const
{
	if (point == m_start || point == m_direction) return true;

	Direct direct(m_start, m_direction);
	if (!direct.contains_point(point)) return false;

	Point center(0.5 * (m_start.get_cartesian_coords().first + m_direction.get_cartesian_coords().first), 
		0.5 * (m_start.get_cartesian_coords().second + m_direction.get_cartesian_coords().second));
	Vector from_start_to_center(m_start, center);
	Vector from_start_to_point(m_start, point);
	Vector from_end_to_center(m_direction, center);
	Vector from_end_to_point(m_direction, point);
	if (from_start_to_center.codirectional(from_start_to_point) && from_end_to_center.codirectional(from_end_to_point)) return true;
	else return false;

}