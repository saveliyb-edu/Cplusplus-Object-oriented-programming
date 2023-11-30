#include "Point.h"
#include "cmath"
#include <iomanip>

Point::Point() {
	this->setX(0.0);
	this->setY(0.0);
}

Point::Point(double x, double y) {
	this->setX(x);
	this->setY(y);
}

Point::Point(const Point& other) {
	setX(other.x_);
	setY(other.y_);
}

Point::~Point() {}

void Point::setX(double value) {
	x_ = value;
}

void Point::setY(double value) {
	y_ = value;
}

double Point::getX() const {
	return x_;
}

double Point::getY() const {
	return y_;
}

bool Point::isEqual(const Point& other) const{
	return getX() == other.getX() && getY() == other.getY();
}

double Point::getDistance(const Point& other) const {
	return sqrt(pow(getX() - other.getX(), 2) + pow(getY() - other.getY(), 2));
}

void Point::move(double k) {
	setX(getX() + k);
	setY(getY() + k);
}

void Point::operator=(const Point& other) {
	setX(other.getX());
	setY(other.getY());
}

bool Point::operator==(const Point& other) const {
	return (getX() == other.getX() && getY() == other.getY());
}

bool Point::operator<(const Point& other) const {
	return ((pow(getX(), 2) + pow(getY(), 2)) < (pow(other.getX(), 2) + pow(other.getY(), 2)));
}

bool Point::operator>=(const Point& other) const {
	return !((pow(getX(), 2) + pow(getY(), 2)) < (pow(other.getX(), 2) + pow(other.getY(), 2)));
}

Point Point::operator+(double k) const {
	return Point(x_ + k, y_ + k);
}

void Point::operator += (double k){
	setX(getX() + k);
	setY(getY() + k);
}

std::istream& operator >> (std::istream& in, Point& obj) {
	double x, y;
	in >> x >> y;
	obj.setX(x);
	obj.setY(y);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Point& obj) {
	return (out << std::fixed << std::setprecision(2) << "(" << obj.getX() << ", " << obj.getY() << ")");
}
