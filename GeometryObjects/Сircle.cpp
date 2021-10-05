#include "Circle.h"

Circle::Circle(const Point& center, double R):m_center(center),m_radius(R) {}

bool Circle::contains_inside(const Point& point) {
	if (pow(point.x - m_center.x, 2) + pow(point.y - m_center.y, 2) < m_radius * m_radius) return true;
	else return false;
}