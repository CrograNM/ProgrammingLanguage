//---------------------------------------------------
// Point.cpp	Point class definition – cpp는 컴파일하여 obj 또는 library로 제공한다
//				2차원 좌표 (x, y)
//				CPP 내용은 컴파일하여 object 파일로 제공됨
//				(- 다른 사용자에게 구현 소스를 감출 수 있다)
//---------------------------------------------------
#include "point.h"

// 클래스 밖에서 멤버를 정의하는 문법 살펴보기
Point::Point() // default constructor
	: x { 0.0 }, y { 0.0 }
{
}

// 인자 두 개를 받는 생성자
Point::Point(double a, double b)
	: x { a }, y { b }
{
}