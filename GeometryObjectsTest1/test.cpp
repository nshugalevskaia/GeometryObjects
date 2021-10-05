#include "gtest/gtest.h"
#include "Polygon.h"

TEST(GeometryTests, TestVectorCollinear) {

	Vector vec1(Point(0, 0), Point(10, 10));
	Vector vec2(Point(0, 0), Point(5, 5));
	Vector vec3(Point(0, 0), Point(5, 0));
	Vector vec4(Point(1, 1), Point(5, 1));
	EXPECT_TRUE(vec1.collinear(vec2));
	EXPECT_FALSE(vec1.collinear(vec3));
	EXPECT_FALSE(vec2.collinear(vec3));
	EXPECT_TRUE(vec3.collinear(vec4));
}

TEST(PolygonTests, Test1) {
	EXPECT_EQ(1, 1);
	//EXPECT_TRUE(true);
}