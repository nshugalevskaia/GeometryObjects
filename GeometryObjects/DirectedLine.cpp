#include "DirectedLine.h"
#include "Direct.h"

DirectedLine::DirectedLine(const Point A, const Point B):m_start(A),m_direction(B){}

bool DirectedLine::codirectional(const DirectedLine& other_line) const
{
	if (m_start == other_line.m_start && m_direction == other_line.m_direction) return true;
	if (!this->collinear(other_line)) return false;

	auto [a1, b1, c1] = other_line.get_line_coeff();
	auto [a2, b2, c2] = this->get_line_coeff();

	if (a1 != 0)
	{
		if (a2 / a1 <= 0) return false;
	}

	if (b1 != 0)
	{
		if (b2 / b1 <= 0) return false;
	}

	return true;
}
std::tuple<double, double, double> DirectedLine::get_line_coeff() const
{
	Direct direct(m_start, m_direction);
	return direct.get_line_coeff();
}

