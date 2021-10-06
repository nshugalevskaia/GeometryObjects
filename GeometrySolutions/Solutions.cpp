#include "Polygon.h"
#include "Circle.h"
#include "Point.h"
#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <unordered_set>
#include "Solutions.h"

DataException::DataException(std::string error) :m_error(error) {};
const char* DataException::what() const noexcept
{
	return m_error.c_str();
}

size_t count_of_points_inside_polygon(std::string fine_ne)
{
	size_t M, N, ans = 0;
	std::vector<Vector> polygon_edges;
	std::ifstream input_file;
	try
	{
		input_file.open(fine_ne);
	}
	catch(std::exception)
	{
		throw DataException("No file.");
	}
	try
	{
		input_file >> N >> M;
		for (int i = 0; i < N; ++i)
		{
			double x1, y1, x2, y2;
			input_file >> x1 >> y1;
			input_file >> x2 >> y2;
			polygon_edges.push_back(Vector(Point(x1,y1),Point(x2,y2)));
		}
	}
	catch (std::exception)
	{
		polygon_edges.clear();
		input_file.close();
		throw DataException("Bad input.");

	}

	Polygon polygon(polygon_edges);

	for (int i = 0; i < M; ++i)
	{
		double x, y;
		try {
			
			input_file >> x >> y;
		}
		catch(std::exception)
		{
			polygon_edges.clear();
			throw DataException("Bad input.");
			input_file.close();
		}
			
		if (polygon.contains_point_inside(Point(x, y)))
		{
			++ans;
		}

	}

	input_file.close();
	return ans;

}

size_t points_near_circle(size_t N, std::multimap<double,Point>& PointsList, Circle circle, double distance_to_circle)
{
	PointsList.clear();
	size_t ans = 0;
	Point center = circle.m_center;
	double R = circle.m_radius, dist = distance_to_circle;
	Circle inner_circle(center, R - dist);
	Circle outer_circle(center, R + dist);
	double max_x = 100, min_x = -100, max_y = 100, min_y = -100;
	std::vector<Point> set_points;

	for (int i = 0; i < N; ++i)
	{
		set_points.push_back(Point(((double)rand() + 1) / ((double)RAND_MAX + 2) * (max_x - min_x) + min_x, ((double)rand() + 1) / ((double)RAND_MAX + 2) * (max_y - min_y) + min_y));
	}


	std::ofstream list_point;
	list_point.open("output_points.txt");
	for (auto i = set_points.begin(); i != set_points.end(); ++i)
	{
		if (!inner_circle.contains_inside(*i) && outer_circle.contains_inside(*i))
		{
			PointsList.insert({ i->get_polar_coords().second, *i });
			list_point << i->x << " " << i->y << std::endl;
			++ans;
		}
	}
	list_point.close();
	set_points.clear();
	return ans;

}

