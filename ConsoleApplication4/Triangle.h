#pragma once
#include "Point.h"

class Triangle {
	friend std::ostream& operator<<(std::ostream& out, const Triangle& obj);
	friend std::istream& operator>>(std::istream& in, Triangle& obj);
private:
	Point a_, b_, c_;
public:
	Triangle();
	Triangle(const Point a, const Point b, const Point c);
	Triangle(const Triangle& other);
	~Triangle();

	void setA(const Point& value);
	void setB(const Point& value);
	void setC(const Point& value);
	Point getA() const;
	Point getB() const;
	Point getC() const;
	bool isTriangle() const;
	void move(double k);
	double getPerimeter() const;
	bool isEqual(const Triangle& other) const;
	double getSquare() const;

	void operator = (const Triangle& other);
	bool operator == (const Triangle& other) const;
	bool operator < (const Triangle& other) const;
	Triangle operator + (double k) const;
	void operator += (double k);
};

