#pragma once

class DataException : public std::exception
{
private:
	std::string m_error;
public:
	DataException(std::string error);
	const char* what() const noexcept override;
};

size_t count_of_points_inside_polygon(std::string fine_ne);
size_t points_near_circle(size_t N, std::multimap<double, Point>& PointsList, Circle circle, double distance_to_circle);