#pragma once

//----------------------------------------------------------------------------
// Triangle.h		세 점으로 삼각형을 정의할 수 있다
//
 // 2025. 11. 28	
//----------------------------------------------------------------------------
#pragma once
#include "point.h"
#include "shape.h"

class Triangle : public Shape {
public:
	Triangle();
	Triangle(const Point&, const Point&, const Point&);
	Triangle(const Triangle&);
	~Triangle();

	virtual void draw() const override;

private:
	Point p1 { }, p2 { }, p3 { };
};