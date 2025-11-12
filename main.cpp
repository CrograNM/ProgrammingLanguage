// ----------------------------------------------------------------------
// 12.15 월요일(15주 1일) - 기말시험(다형성)
// ----------------------------------------------------------------------
// operator overloading - 연산자 오버로딩 
// ----------------------------------------------------------------------

#include <iostream>
#include <string>
#include "save.h"
#include "STRING.h"
using namespace std;

extern bool 관찰; // 관찰하고 싶으면 true로 바꾸자

//--------
int main()
//--------
{
	관찰 = true;

	STRING s1 { "2025년 11월 12일" };
	STRING s2 { " - 내일은 수능시험일" };
	STRING s3 = s1 + s2;		// RVO, Return Value Optimization (컴파일러 최적화 기법)
	s3.show();

	save("main.cpp");
}