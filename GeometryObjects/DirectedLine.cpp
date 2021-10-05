#include "DirectedLine.h"
#include "Direct.h"

DirectedLine::DirectedLine(const Point A, const Point B):m_start(A),m_direction(B){}

bool DirectedLine::codirectional(const DirectedLine& other_line) const
{
	auto start1 = m_start.get_cartesian_coords();
	auto end1 = m_direction.get_cartesian_coords();
	auto start2 = other_line.m_start.get_cartesian_coords();
	auto end2 = other_line.m_direction.get_cartesian_coords();

	if (this->collinear(other_line) && ((end1.first - start1.first) / (end2.first - start2.first) > 0))
		return true;
	else return false;
}
std::tuple<double, double, double> DirectedLine::get_line_coeff() const
{
	Direct direct(m_start, m_direction);
	return direct.get_line_coeff();
}

