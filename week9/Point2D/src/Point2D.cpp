#include "Point2D.h"

Point2D::Point2D(int x, int y) : m_x(x), m_y(y), m_distance(sqrt(pow(m_x, 2) + pow(m_y, 2))) {}

bool Point2D::operator<(const Point2D& other) const {
	return m_distance < other.m_distance;
}

int Point2D::getX() const {
	return m_x;
}

int Point2D::getY() const {
	return m_y;
}

void Point2D::Print() const {
	PrintPoint(*this);
}

void Point2D::PrintPoint(const Point2D point) {
	std::cout << "Point coordinates (" << point.m_x << ", " << point.m_y 
			  << ") distance from origin: " << point.m_distance << std::endl;
}

void Point2D::FunctionPrintY(const Point2D& point) {
	std::cout << "Function print y=" << point.m_y << std::endl;
}

void FunctionPrintX(const Point2D& point) {
	std::cout << "Function print x=" << point.getX() << std::endl;
}

bool MaxDistanceAsc(const Point2D& point1, const Point2D& point2) {
	return (point1.m_x > point1.m_y ? point1.m_x : point1.m_y) 
		   <
		   (point2.m_x > point2.m_y ? point2.m_x : point2.m_y);
}

bool OrderAscX::operator() ( Point2D point1,  Point2D point2) const {
	return point1.getX() < point2.getX();
}

bool OrderDescY::operator() ( Point2D point1,  Point2D point2) const {
	return point1.getY() > point2.getY();
}
