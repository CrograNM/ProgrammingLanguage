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
};

#endif // _Shape