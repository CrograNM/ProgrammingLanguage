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

	virtual int getID() const override { return 2; } // 2번은 사각형
	virtual void save(std::ofstream& fout) const override;
	virtual void load(std::ifstream& fin) override;

private:
	Point p1, p2;
};