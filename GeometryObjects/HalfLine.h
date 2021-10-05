#pragma once
#include "DirectedLine.h"

class HalfLine final:public DirectedLine
{
public:

	HalfLine() = delete;
	HalfLine(const HalfLine&) = default;
	HalfLine(Point A, Point D);

	bool contains_point(const Point& point) const override;
	
};


