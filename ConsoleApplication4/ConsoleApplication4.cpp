#include <iostream>
#include "Point.h"
#include "Triangle.h"

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
	testPoint();
	testTriangle();
	return 0;
}