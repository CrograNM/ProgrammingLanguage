#pragma once
//----------------------------------------------------------------------------
// Rectangle.h		대각선에 있는 점 2개로 사각형을 정의할 수 있다
//
// 2025. 11. 28
//----------------------------------------------------------------------------

#pragma once
#include "point.h"
#include "shape.h"

class Rectangle : public Shape {
public:
	Rectangle();
	Rectangle(const Point&, const Point&);
	Rectangle(const Rectangle&);
	~Rectangle();

	virtual void draw() const override;

private:
	Point p1, p2;
};