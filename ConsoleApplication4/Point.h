#pragma once
#include <iostream>

class Point {
	friend std::istream& operator>>(std::istream& in, Point& obj);
	friend std::ostream& operator<<(std::ostream& out, const Point& obj);

private:
	double x_;
	double y_;
public:
	Point();
	Point(double x, double y);
	Point(const Point& other);
	~Point();

	void setX(double x);
	void setY(double y);
	double getX() const;
	double getY() const;
	bool isEqual(const Point& other) const;
	double getDistance(const Point& other) const;
	void move(double k);

	void operator = (const Point& other);
	bool operator == (const Point& other) const;
	bool operator < (const Point& other) const;
	bool operator >= (const Point& other) const;
	Point operator + (double k) const;
	void operator += (double k);
};
