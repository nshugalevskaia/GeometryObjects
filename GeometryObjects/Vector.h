#pragma once
#include "Point.h"
#include "DirectedLine.h"
 

class Vector final :public DirectedLine 
{
public:

	Vector() = delete;
	Vector(const Vector&) = default;
	Vector(Point A, Point B);
	bool contains_point(const Point& point) const override;

};

