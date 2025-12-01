#pragma once

//---------------------------------------------------
// Point.h		Point class declaration
//				2차원 좌표 (x, y)를 나타낸다.
//---------------------------------------------------

#ifndef _Point // 한 번만 include 할 수 있도록 함
#define _Point

struct Point
{
	double x {}, y {};

	Point();						// default constructor
	Point(double x, double y);		
	Point(const Point&) = default;	// copy constructor (default : 사용자가 만들 필요 없음)
};


#endif // _Point