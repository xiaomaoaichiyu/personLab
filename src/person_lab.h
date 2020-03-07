#pragma once
#include <vector>
#include <set>
#include <string>
#include <iostream>
#include <tuple>
#include <fstream>

class Point {
	double x;
	double y;
public:
	Point() {
		this->x = 0;
		this->y = 0;
	}
	Point(double X, double Y) {
		this->x = X;
		this->y = Y;
	}
	bool operator<(const Point& a) const {
		if (this->x < a.x) {
			return true;
		}
		else if (this->x == a.x) {
			return this->y < a.y;
		}
		else {
			return false;
		}
	}
	bool operator==(const Point& a) const {
		if (this->x == a.x && this->y == a.y) {
			return true;
		}
		else {
			return false;
		}
	}
	void setX(double X) {
		this->x = X;
	}
	void setY(double Y) {
		this->y = Y;
	}
};

//ax + by + c = 0
//a = y1 - y2
//b = x2 - x1
//c = x1y2 - x2y1
struct Line {
	double x1, y1;
	double x2, y2;
public:
	Line(double x1, double y1, double x2, double y2) {
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;
	}
};

/*
	return (x0, y0) of two lines
	a1x + b1y + c1 = 0
	a2x + b2y + c2 = 0
	D = a1 * b2 - a2 * b1. if D == 0: means two line are parallel
	other:
	get x0 and y0.
*/
bool getCross(Line l1, Line l2, Point* res);

int getAllIntersrc(std::vector<Line> lines);