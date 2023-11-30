#include "Triangle.h"
#include <iomanip>

using namespace std;

Triangle::Triangle() {
	a_ = Point();
	b_ = Point();
	c_ = Point();
}

Triangle::Triangle(const Point a, const Point b, const Point c) {
	this->setA(a);
	this->setB(b);
	this->setC(c);
}

Triangle::Triangle(const Triangle& other) {
	setA(other.a_);
	setB(other.b_);
	setC(other.c_);
}

Triangle::~Triangle(){}

void Triangle::setA(const Point& value) {
	a_ = value;
}

void Triangle::setB(const Point& value) {
	b_ = value;
}

void Triangle::setC(const Point& value) {
	c_ = value;
}

Point Triangle::getA() const {
	return a_;
}

Point Triangle::getB() const {
	return b_;
}

Point Triangle::getC() const {
	return c_;
}

bool Triangle::isTriangle() const {
	double ab = a_.getDistance(b_);
	double ac = a_.getDistance(c_);
	double bc = b_.getDistance(c_);
	if (ab == 0 && bc == 0 && ac == 0) {
		return true;
	}
	return 2 * max(ab, max(ac, bc)) < Triangle::getPerimeter();
}

void Triangle::move(double k) {
	a_.move(k);
	b_.move(k);
	c_.move(k);
}

double Triangle::getPerimeter() const {
	return b_.getDistance(c_) + a_.getDistance(c_) + a_.getDistance(b_);
}


bool Triangle::isEqual(const Triangle& other) const {
	return
		(a_.isEqual(other.a_) && b_.isEqual(other.b_) && c_.isEqual(other.c_)) ||
		(a_.isEqual(other.a_) && b_.isEqual(other.c_) && c_.isEqual(other.b_)) ||
		(a_.isEqual(other.b_) && b_.isEqual(other.c_) && c_.isEqual(other.a_)) ||
		(a_.isEqual(other.c_) && b_.isEqual(other.a_) && c_.isEqual(other.b_)) ||
		(a_.isEqual(other.c_) && b_.isEqual(other.b_) && c_.isEqual(other.a_)) ||
		(a_.isEqual(other.b_) && b_.isEqual(other.a_) && c_.isEqual(other.c_));
}

double Triangle::getSquare() const {
	double p = getPerimeter() / 2;
	return sqrt(p *(p - a_.getDistance(b_)) * (p - a_.getDistance(c_)) * (p - b_.getDistance(c_)));
}

void Triangle::operator=(const Triangle& other) {
	setA(other.getA());
	setB(other.getB());
	setC(other.getC());
}

bool Triangle::operator==(const Triangle& other) const {
	Point a1 = getA(), b1 = getB(), c1 = getC(), 
		a2 = other.getA(), b2 = other.getB(), c2 = other.getC();
	
	return ((a1 == a2 && ((b1 == b2 && c1 == c2) || (b1 == c2 && c1 == b2))) ||
		(a1 == b2 && ((b1 == a2 && c1 == c2) || (b1 == c2 && c1 == a2))) ||
		(a1 == c2 && ((b1 == a2 && c1 == b2) || (b1 == b2 && c1 == a2))) ||
		(b1 == b2 && ((a1 == a2 && c1 == c2) || (a1 == c2 && c1 == a2))) ||
		(b1 == c2 && ((a1 == a2 && c1 == b2) || (a1 == b2 && c1 == a2))) ||
		(c1 == c2 && ((a1 == a2 && b1 == b2) || (a1 == b2 && b1 == c2))));
}

bool Triangle::operator<(const Triangle& other) const {
	return getSquare() < other.getSquare();
}

Triangle Triangle::operator+(double k) const {
	return Triangle(getA() + k, getB() + k, getC() + k);
}

void Triangle::operator+=(double k) {
	setA(getA() + k);
	setB(getB() + k);
	setC(getC() + k);
}

std::ostream& operator<< (std::ostream& out, const Triangle& obj) {
	out << std::fixed << std::setprecision(2) << "<Triangle:" << "(" << "\n\t" << obj.getA() << ",\n\t" << obj.getB() << ",\n\t" << obj.getC() << "\n)";
	return out;
}

std::istream& operator>> (std::istream& in, Triangle& obj) {
	Point a, b, c;
	in >> a >> b >> c;
	obj.setA(a);
	obj.setB(b);
	obj.setC(c);
	return in;
}
