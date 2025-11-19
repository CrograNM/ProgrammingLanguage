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
	STRING s { "2025년 11월 19일" };
	for (int i = 0; i < s.length(); ++i) { 
		// cout << s[i] << endl;
		// cout << s.operator[](i) << endl;
	}

	save("main.cpp");
}