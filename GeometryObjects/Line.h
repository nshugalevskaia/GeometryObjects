#pragma once
#include "Point.h"
#include <tuple>
class Line
{
public:
	enum LineTypes { direct, halfline, vect };

	class LineException: public std::exception
	{
	private:
		std::string m_error;
	public:
		LineException(std::string error);
		const char* what() const noexcept override; 
	};


	bool intersect(const Line& other_line) const;
	bool collinear(const Line& other_line) const;
	bool operator ==(const Line& other_line) const;

	Point extending_intersection_point(const Line& other_line) const; //пересечение продолжения линий (прямых на которых лежит луч/сегмент)
	Point intersection_point(const Line& other_line) const; //пересечение линий (сегмент/луч)

	virtual bool contains_point(const Point& point) const = 0;
	virtual std::tuple<double, double, double> get_line_coeff() const = 0;

};

