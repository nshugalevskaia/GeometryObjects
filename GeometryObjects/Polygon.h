#pragma once
#include "Point.h"
#include "Vector.h"
#include "HalfLine.h"
#include <vector>
 

class Polygon
{
public: 

	Polygon() = delete;
	Polygon(const std::vector<Vector>& input);
	bool contains_point_inside(const Point& point);
	~ Polygon();

private:
	std::vector<Vector> edges;
	size_t edge_count;
};

