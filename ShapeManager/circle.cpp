//----------------------------------------------------------------------------
// Circle.cpp		
//					
//
// 2025. 11. 28		by Wulong
//----------------------------------------------------------------------------

#include <iostream>
#include "circle.h"

Circle::Circle() 
	: center{ }, rad{ 0.0 } 
{
	std::cout << "Circle 기본생성자 호출\n";
}

Circle::Circle(const Point& c, double r)
	: center{ c }, rad{ r } 
{
	std::cout << "Circle 생성자 호출 - 중심점(" << center.x << "," << center.y
		<< ") 반지름 " << rad << '\n';
}

// 복사생성자를 프로그램할 이유가 있다면 멤버변수의 값을 복새해야한다.
// 만약 아무것도 하지 않으면 멤버변수는 복사되지 않는다.
Circle::Circle(const Circle& other)
	: center{ other.center }, rad{ other.rad } 
{
	std::cout << "Circle 복사생성자 호출 - 중심점(" << center.x << "," << center.y
		<< ") 반지름 " << rad << '\n';
}

Circle::~Circle() 
{
	// 소멸자를 프로그램할 필요가 없다
	// -> 동적 메모리를 사용하지 않기 때문
	std::cout << "Circle 소멸자 호출\n";
}

void Circle::draw() const 
{ 
	// 그림 대신 문자로 정보 출력
	std::cout << "원 - 중심점(" << center.x << "," << center.y
		<< ") 반지름 " << rad << '\n';
};