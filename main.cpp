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

	// [문제] s의 글자 중에서 숫자를 "*"로 바꿔라.
	for (int i = 0; i < s.length(); ++i) {
		if (isdigit(s[i])) {
			s[i] = '*';			// lvalue - location value 
								// value - category
		}
	}

	cout << s << endl; // ****년 **월 **일

	// save("main.cpp");
}