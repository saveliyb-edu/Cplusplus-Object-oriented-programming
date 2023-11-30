#include <iostream>
#include "Point.h"
#include "Triangle.h"
//
//
//const std::string ERROR_OPEN_FILE = "Ожидалось число с плавующей точкой";
//
//bool inputPoint(Point& point);
//void outputPoint(Point& point);
//bool isPointInCircle(double radius, Point& point);
//bool isEqualSquare(Triangle& triangle1, Triangle& triangle2);
//void outputTriangle(Triangle& triangle);
//
//int main() {
//	setlocale(LC_ALL, "ru");
//	Point point1, pointZero(0.0, 0.0);
//	double minDistance;
//	if (!inputPoint(point1)) return 0;
//	Point pointNearest(point1);
//	minDistance = pointNearest.getDistance(pointZero);
//	while (point1.getX() != 0 || point1.getY() != 0) {
//		double distance = point1.getDistance(pointZero);
//		if (distance < minDistance) {
//			Point pointNearest(point1);
//			minDistance = distance;
//		}
//		if (!inputPoint(point1)) return 0;
//	}
//	outputPoint(pointNearest);
//
//
//	//Point a(4, 5);
//	//Point b(4, 6);
//	//Point c(7, 10);
//	//Triangle tr1(a, b, c);
//	//outputTriangle(tr1);
//	//Triangle tr2(c, b, a);
//	//std::cout << isEqualSquare(tr1, tr2);
//
//
//	return 0;
//}
//
//
//bool inputPoint(Point& point) {
//	double x, y;
//
//	std::cout << "Введите координаты точки x, y: " << std::endl;
//	std::cin >> x >> y;
//	std::cout << std::endl;
//	if (std::cin.fail()) {
//		std::cout << "Ожидалось число с плавующей точкой";
//		return false;
//	}
//
//	point.setX(x);
//	point.setY(y);
//
//	return true;
//}
//
//void outputPoint(Point& point) {
//	std::cout << "(" << point.getX() << ", " << point.getY() << ")";
//}
//
//bool isPointInCircle(double radius, Point & point) {
//	Point center(0, 0);
//	return point.getDistance(center) <= radius;
//}
//
//
//bool isEqualSquare(Triangle& triangle1, Triangle& triangle2) {
//	return (triangle1.getSquare() == triangle2.getSquare());
//}
//
//void outputTriangle(Triangle& triangle) {
//	std::cout << "(";
//	Point a = triangle.getA(), b = triangle.getB(), c = triangle.getC();
//	outputPoint(a);
//	std::cout << "; ";
//	outputPoint(b);
//	std::cout << "; ";
//	outputPoint(c);
//	std::cout << ")\n";
//}



// testPoint.cpp
#include "Point.h"
using namespace std;

void testPoint()
{
	std::cout << "begin testPoint():\n";
	{
		cout << "1: Point p1(10, 10), p2(5, 3), p3;\n";
		Point p1(10, 10);
		Point p2(5, 3);
		Point p3;
		cout << "2: p4(p1), p5 = p2;\n";
		{
			Point p4(p1);
			Point p5 = p2;
		}
		std::cout << "3: p3 = p1 + 7;\n";
		p3 = p1 + 7;
		std::cout << "4: p3 = p1;\n";
		p3 = p1;
		std::cout << "5: p3 = p1;\n";
		if (p1 == p2) {
			std::cout << "объекты равны\n";
		}
		std::cout << "7: p2 < p1?\n";
		if (p2 < p1) {
			std::cout << "да\n";
		}
	}
	std::cout << "end testPoint().\n";
	return;
}

void testTriangle() {
	std::cout << "begin testTriangle():\n";
	{
		cout << "1: Point p1(10, 10), p2(5, 3), p3;\n";
		Point p1(10, 10);
		Point p2(5, 3);
		Point p3;
		cout << "2: p4(p1), p5 = p2;\n";
		std::cout << "3: p3 = p1 + 7;\n";

		Triangle tr1(p1, p2, p3);
		Triangle tr2;
		std::cout << "7: tr1 = " << tr1 << "; \n";
		std::cout << "8: tr2 = " << tr2 << "; \n";
		tr2 = tr1;
		std::cout << "9: tr1 == tr2?;\n";
		if (tr2 == tr1) {
			std::cout << "объекты равны\n";
		}
		tr2 += 7;
		std::cout << "10: tr2 = " << tr2 << "; \n";
		Triangle tr3(p1 + 2, p3, p2);
		std::cout << "11: tr3 = " << tr3 << "; \n";
		std::cout << "12: tr3 < tr1?\n";
		if (tr1 < tr3) {
			std::cout << "да\n";
		}
	}
	std::cout << "end testTriangle().\n";
	return;
}

const Point GLOBAL_POINT(1, 1);
int main()
{
	setlocale(LC_ALL, "rus");
	//testPoint();
	//testTriangle();
	Triangle a;
	std::cin >> a;
	std::cout << a;
	return 0;
}