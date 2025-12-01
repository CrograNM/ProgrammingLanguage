#pragma once
//----------------------------------------------------------------------------
// Line.h       시작점과 끝점으로 선분을 정의한다
//----------------------------------------------------------------------------

#include "point.h"
#include "shape.h"
#include <fstream> // 파일 입출력을 위해 필요

class Line : public Shape {
public:
    Line();
    Line(const Point&, const Point&);
    Line(const Line&);
    virtual ~Line();

    // 가상 함수 오버라이딩 (다형성 구현)
    virtual void draw() const override;

    virtual int getID() const override { return 4; } // Line의 ID는 4로 지정
    virtual void save(std::ofstream& fout) const override;
    virtual void load(std::ifstream& fin) override;

private:
	Point p1, p2; // 선분의 시작점과 끝점
};
