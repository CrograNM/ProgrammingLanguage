#pragma once

//---------------------------------------------------
// Shape.h		class Shape - Virtual Base Class
//				이 클래스는 추상 클래스(abstract class)이다.
//---------------------------------------------------

#ifndef _Shape	// _Shape이 앞에서 정의되지 않았다면
#define _Shape	// _Shape 정의

class Shape {
public:
	Shape() { };
	virtual ~Shape() { }; // virtual 추가 
	virtual void draw() const = 0;	// 순수 가상 함수(pure virtual function)

	// [추가된 부분]
	virtual int getID() const = 0;					// 도형의 종류 식별 (1:삼각형, 2:사각형, 3:원)
	virtual void save(std::ofstream& fout) const = 0; // 파일에 내 정보 쓰기
	virtual void load(std::ifstream& fin) = 0;        // 파일에서 정보 읽어오기
};

#endif // _Shape