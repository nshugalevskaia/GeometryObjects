#include "Line.h"


Line::LineException::LineException(std::string error) :m_error(error) {};
const char* Line::LineException::what() const noexcept
{
	return  m_error.c_str();
}

bool Line::collinear(const Line& other_line) const
{
	auto [a1, b1, c1] = this->get_line_coeff();
	auto [a2, b2, c2] = other_line.get_line_coeff();
	if (a2 == 0 && a1 == 0) return true;
	if (b2 == 0 && b1 == 0) return true;
	if (a2 == 0 || a1 == 0) return false;
	if (b2 == 0 || b1 == 0) return false;
	if (a1 / a2 == b1 / b2) return true;
	else return false;
}

bool Line::operator ==(const Line& other_line) const
{
	auto [a1, b1, c1] = this->get_line_coeff();
	auto [a2, b2, c2] = other_line.get_line_coeff();
	if (a1==a2 && b1==b2 && c1==c2)
		return true;
	else return false;
}

bool Line::intersect(const Line& other_line) const
{
	auto [a1, b1, c1] = this->get_line_coeff();
	auto [a2, b2, c2] = other_line.get_line_coeff();

	if (this->collinear(other_line)) return false; //совпадающие прямые (лежащие на одной прямой) не считаются пересекающимся

	Point intersection = extending_intersection_point(other_line);
	if (this->contains_point(intersection) && other_line.contains_point(intersection)) return true;
	else return false;
}

Point Line::intersection_point(const Line& other_line) const
{
	if (!intersect(other_line)) throw LineException("there is not intersection point: lines are collinear or the intersection point lays outside the segment");
	else return extending_intersection_point(other_line);
}

Point Line::extending_intersection_point(const Line& other_line) const
{
	if (collinear(other_line)) throw LineException("lines are collinear, there is not intersection point");

	auto [a1, b1, c1] = this->get_line_coeff();
	auto [a2, b2, c2] = other_line.get_line_coeff();

	double x, y;
	if (b1 != 0 && b2 != 0 && a1 != 0 && a2 != 0)
	{
		x = (b2 * c1 - b1 * c2) / (a2 * b1 - a1 * b2);
		y = -(a1 * x + c1) / b1;
	}
	if (b1 == 0)
	{
		x = -c1 / a1;
		y = -(a2 * x + c2) / b2;
	}
	if (b2 == 0)
	{
		x = -c2 / a2;
		y = -(a1 * x + c1) / b1;
	}
	if (a1 == 0)
	{
		y = -c1 / b1;
		x = -(b2 * y + c2) / a2;
	}
	if (a2 == 0)
	{
		y = -c2 / b2;
		x = -(b1 * y + c1) / a1;
	}

	return Point(x, y);

}
