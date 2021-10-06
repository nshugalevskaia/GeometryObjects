#include "pch.h"
#include "Polygon.h"
#include "Circle.h"
#include <map>
#include "Solutions.h"
#include <fstream>
#include "Constants.h"
TEST(GeometryTests, TestCollinear) {

	Vector vec1(Point(0, 0), Point(10, 10));
	Vector vec2(Point(0, 0), Point(5, 5));
	Vector vec3(Point(0, 0), Point(5, 0));
	Vector vec4(Point(1, 1), Point(5, 1));
	Direct dir1(3, 7, 8);
	Direct dir2(6, 14, 8);
	Direct dir3(6,- 14, 8);
	HalfLine hl1(Point(0, 0), Point(20, 20));
	EXPECT_TRUE(vec1.collinear(vec2));
	EXPECT_FALSE(vec1.collinear(vec3));
	EXPECT_FALSE(vec2.collinear(vec3));
	EXPECT_TRUE(vec3.collinear(vec4));
	EXPECT_TRUE(dir1.collinear(dir2));
	EXPECT_FALSE(dir1.collinear(dir3));
	EXPECT_TRUE(hl1.collinear(vec1));
	
}

TEST(GeometryTests, TestCodirection) {
	Vector vec1(Point(0, 0), Point(10, 10));
	Vector vec2(Point(10, 10), Point(5, 5));
	Vector vec3(Point(1, 5), Point(0, 0));
	Vector vec4(Point(0, 0), Point(5, 5));
	Vector vec5(Point(12, 20), Point(7, 15));
	HalfLine hl1(Point(0, 0), Point(20, 20));
	HalfLine hl2(Point(20, 20), Point(0, 0));
	EXPECT_TRUE(vec1.codirectional(vec4));
	EXPECT_TRUE(vec2.codirectional(vec5));
	EXPECT_FALSE(vec1.codirectional(vec2));
	EXPECT_FALSE(vec1.codirectional(vec3));
	EXPECT_FALSE(vec2.codirectional(vec3));
	EXPECT_FALSE(vec3.codirectional(vec4));
	EXPECT_FALSE(hl1.codirectional(hl2));
	EXPECT_TRUE(hl1.codirectional(vec1));
}

TEST(GeometryTests, TestIntersection) {
	Vector vec1(Point(0, 0), Point(10, 10));
	Vector vec2(Point(0, 0), Point(5, 5));
	Vector vec3(Point(1, 5), Point(5, 1));
	Vector vec4(Point(0, 0), Point(10, 0));
	Vector vec5(Point(5, -5), Point(5, 5));
	Vector vec6(Point(-5, -5), Point(-5, 5));
	Direct dir1(6, 14, 8);
	Direct dir2(6, -14, 8);
	Direct dir3(6, 14, 19);
	EXPECT_FALSE(vec1.intersect(vec2));
	EXPECT_TRUE(vec1.intersect(vec3));
	EXPECT_FALSE(dir1.intersect(dir3));
	EXPECT_TRUE(dir1.intersect(dir2));
	EXPECT_TRUE(vec5.intersect(vec4));
	EXPECT_FALSE(vec6.intersect(vec4));
	EXPECT_TRUE(vec5.intersection_point(vec4) == Point(5,0));
}


TEST(PolygonTests, Test1) {
	size_t count;
	try { count = count_of_points_inside_polygon("poly_test1.txt"); }
	catch (std::exception e) { std::cerr << e.what(); }
	size_t realcount;
	std::ifstream file_ans;
	try {
		try { file_ans.open("poly_test1_answer.txt"); }
		catch (std::exception e) { throw e; }
		try { file_ans >> realcount; }
		catch (std::exception e) { throw e; }
	}
	catch (std::exception e) { std::cerr << e.what(); }

	EXPECT_EQ(count, realcount);
}

TEST(PolygonTests, Test2) {
	size_t count;
	try { count = count_of_points_inside_polygon("poly_test2.txt"); }
	catch (std::exception e) { std::cerr << e.what(); }
	size_t realcount;
	std::ifstream file_ans;
	try {
		try { file_ans.open("poly_test2_answer.txt"); }
		catch (std::exception e) { throw e; }
		try { file_ans >> realcount; }
		catch (std::exception e) { throw e; }
	}
	catch (std::exception e) { std::cerr << e.what(); }

	EXPECT_EQ(count, realcount);
}

TEST(PolygonTests, Test3) {
	size_t count;
	try { count = count_of_points_inside_polygon("poly_test3.txt"); }
	catch (std::exception e) { std::cerr << e.what(); }
	size_t realcount;
	std::ifstream file_ans;
	try {
		try { file_ans.open("poly_test3_answer.txt"); }
		catch (std::exception e) { throw e; }
		try { file_ans >> realcount; }
		catch (std::exception e) { throw e; }
	}
	catch (std::exception e) { std::cerr << e.what(); }

	EXPECT_EQ(count, realcount);
}


TEST(CircleTests, Test1) {
	
	Circle tst({ 0,0 }, 80);
	EXPECT_TRUE(tst.contains_inside({ 20,20 }));
	EXPECT_FALSE(tst.contains_inside({ 60, 60 }));
	EXPECT_FALSE(tst.contains_inside({ 80, 0 }));
}

TEST(CircleTests, Test2) {
	std::multimap<double, Point> points;
	points_near_circle(100, points, Circle({ 0,0 }, 80),10);
	double prev_ang = -2*PI;
	for (auto i = points.begin(); i != points.end(); ++i)
	{
		EXPECT_TRUE(pow(i->second.x,2)+ pow(i->second.y, 2) < 90 * 90);
		EXPECT_TRUE(pow(i->second.x, 2) + pow(i->second.y, 2) >= 70 * 70);
		EXPECT_TRUE(prev_ang < i->first);
	}
}
