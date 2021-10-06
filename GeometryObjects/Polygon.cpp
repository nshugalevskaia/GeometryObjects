#include "Polygon.h"
#include "Line.h"
#include "Constants.h"

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
		if (curr_edge.contains_point(point)) return false;
		if (curr_edge.intersect(router))
		{
			Point intersection = curr_edge.intersection_point(router);
			if (curr_edge.m_start == intersection || curr_edge.m_direction == intersection) //если луч попадает в вершину
			{  
				auto [a, b, c] = router.get_line_coeff();				
				Point compare1(curr_edge.m_start.x, -(curr_edge.m_start.x * a + c) / b);
				Point compare2(curr_edge.m_direction.x, -(curr_edge.m_direction.x * a + c) / b);
				if (compare2.upper(curr_edge.m_direction)
					&& (curr_edge.m_start.upper(compare1) || compare1 == curr_edge.m_start))
					{ ++intersection_count; continue;}
				if ((curr_edge.m_direction.upper(compare2)|| compare2 == curr_edge.m_direction)
					&& compare1.upper(curr_edge.m_start))
					{ ++intersection_count; continue;}
			}
			else
			{
				++intersection_count;
			}	
		}
	}
	if (intersection_count % 2 == 0) return false;
	else return true;
}



