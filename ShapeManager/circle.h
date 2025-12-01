//----------------------------------------------------------------------------
// Circle.h			중심점의 좌표와 반지름으로 원을 정의할 수 있다.
//					(다른 방식으로 원을 정의할 수도 있다)
//
// 2025. 11. 28		by Wulong
//----------------------------------------------------------------------------

#pragma once
#include "point.h"
#include "shape.h"

// 위의 두 include 대신 다음처럼 forward declaration을 사용할 수도 있다.
// struct Point;
// class Shape;

class Circle : public Shape {
public:
	Circle();
	Circle(const Point&, double);	// int -> double
	Circle(const Circle&);	// 깊은 복사를 할 필요가 없으면 프로그래머가 복사 생성자를 정의할 필요 없음
							// 만약 프로그램 해야 한다면 메모리를 이해하고 코딩하기

	// 위 설명을 다음 줄과 같이 선언하여 대체하거나 생략 가능
	// Circle(const Circle&) = default;
	~Circle();				// 소멸자를 프로그램할 필요가 없다는 것을 생각

	virtual void draw() const override;

	virtual int getID() const override { return 3; } // 3번은 원
	virtual void save(std::ofstream& fout) const override;
	virtual void load(std::ifstream& fin) override;

private:
	Point center {};	// 원의 중심점 좌표
	double rad {};		// 원의 반지름
};