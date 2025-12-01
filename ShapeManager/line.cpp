//-----------------------------------------
// Line.cpp
//-----------------------------------------

#include <iostream>
#include "Line.h"

Line::Line()
    : p1 {}, p2 {}
{
	std::cout << "Line 기본생성자 호출\n";
}

Line::Line(const Point& start, const Point& end)
    : p1 { start }, p2 { end }
{
    std::cout << "Line 생성자 호출 - (" << p1.x << "," << p1.y << ") -> ("
        << p2.x << "," << p2.y << ")\n";
}

Line::Line(const Line& other)
    : p1 { other.p1 }, p2 { other.p2 }
{
    std::cout << "Line 복사생성자 호출 - (" << p1.x << "," << p1.y << ") -> ("
		<< p2.x << "," << p2.y << ")\n";
}

Line::~Line()
{
    std::cout << "Line 소멸자 호출\n";
}

void Line::draw() const
{
    std::cout << "선 - 시작점(" << p1.x << "," << p1.y << "), 끝점("
        << p2.x << "," << p2.y << ")" << '\n';
}

void Line::save(std::ofstream& fout) const
{
    // 저장 순서: x1 y1 x2 y2
    fout << p1.x << " " << p1.y << " " << p2.x << " " << p2.y << std::endl;
}

void Line::load(std::ifstream& fin)
{
    // 읽기 순서: x1 y1 x2 y2
    fin >> p1.x >> p1.y >> p2.x >> p2.y;
}
