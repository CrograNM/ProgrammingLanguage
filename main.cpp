// ----------------------------------------------------------------------
// 12.15 월요일(15주 1일) - 기말시험(다형성)
// ----------------------------------------------------------------------
// Modern C++ (C++11) - move semantics (이동 의미론)
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
	std::string s1 { "2025년 11월 19일" };
	std::string s2 { "11주 2일" };

	cout << "s1 - " << s1 << endl;
	cout << "s2 - " << s2 << endl;
	
	save("main.cpp");
}