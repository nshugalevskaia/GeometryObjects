#include "Polygon.h"
#include "Line.h"

Polygon::Polygon(const std::vector<Vector>& input)
{
	edge_count = input.size();
	for (auto it = input.begin(); it != input.end(); ++it)
	{
		edges.push_back(*it);
	}
};

Polygon::~Polygon() {
	edges.clear();
}
bool Polygon::contains_point_inside(const Point& point)
{
	int intersection_count = 0;
	HalfLine router(point, Point(point.x + 100, point.y)); //выпускаем луч в произвольном направлении
	for (auto i = edges.begin(); i != edges.end(); ++i)
	{
		Vector curr_edge = *i;
		if (curr_edge.intersect(router))
		{
			if (curr_edge.m_start != curr_edge.intersection_point(router) //учитываем лучи, проходящие через концы граней, но не начало
				&& !curr_edge.contains_point(router.m_start))
			++intersection_count;
		}
	}
	if (intersection_count % 2 == 0) return false;
	else return true;
}



