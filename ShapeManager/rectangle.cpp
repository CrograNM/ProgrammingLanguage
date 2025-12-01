//-----------------------------------------
// Rectangle.cpp
// 2025. 11. 28
//-----------------------------------------

#include <iostream>
#include "rectangle.h"

Rectangle::Rectangle()
	: p1 { }, p2 { }
{
	std::cout << "Rectangle 기본생성자 호출\n";
}

Rectangle::Rectangle(const Point& a, const Point& b)
	: p1 { a }, p2 { b }
{
	std::cout << "Rectangle 생성자 호출 - (" << p1.x << "," << p1.y << "), ("
		<< p2.x << "," << p2.y << ")\n";
}

Rectangle::Rectangle(const Rectangle& other)
	: p1 { other.p1 }, p2 { other.p2 }
{
	std::cout << "Rectangle 복사생성자 호출 - (" << p1.x << "," << p1.y << "), ("
		<< p2.x << "," << p2.y << ")\n";
}

Rectangle::~Rectangle()
{
	std::cout << "Rectangle 소멸자 호출\n";
}

void Rectangle::draw() const
{
	std::cout << "사각형 - (" << p1.x << "," << p1.y << "), ("
		<< p2.x << "," << p2.y << ")" << '\n';
}