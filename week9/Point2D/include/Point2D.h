#pragma once

#include <cmath>
#include <iostream>

class Point2D {

	friend bool MaxDistanceAsc(const Point2D& point1, const Point2D& point2);

private:
	int m_x;
	int m_y;
	double m_distance;

public:
	Point2D(int x, int y);

	bool operator<(const Point2D& other) const;

	int getX() const;
	int getY() const;

	void Print() const;

	static void PrintPoint(const Point2D point);

	static void FunctionPrintY(const Point2D& point);

};

bool MaxDistanceAsc(const Point2D& point1, const Point2D& point2);

class OrderAscX {
public:
	bool operator() (const Point2D point1, const Point2D point2) const;
};

class OrderDescY {
public:
	bool operator() (const Point2D point1, const Point2D point2) const;
};

void FunctionPrintX(const Point2D& point);
