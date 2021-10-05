#pragma once
#include"Line.h"

class DirectedLine:public Line
{
public:

	DirectedLine() = delete;
	DirectedLine(const DirectedLine&) = default;
	DirectedLine(const Point A, const Point B);

	bool codirectional(const DirectedLine& other_line) const;
	std::tuple<double, double, double> get_line_coeff() const override;

	const Point m_start;
	const Point m_direction;
};
