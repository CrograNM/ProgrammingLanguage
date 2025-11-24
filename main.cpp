// ----------------------------------------------------------------------
// 12.15 월요일(15주 1일) - 기말시험(다형성)
// ----------------------------------------------------------------------
// Modern C++ (C++11) - move semantics (이동 의미론)
// ----------------------------------------------------------------------

#include <iostream>
#include <string>
#include <algorithm>
#include "save.h"
#include "STRING.h"
using namespace std;

extern bool 관찰; // 관찰하고 싶으면 true로 바꾸자

//--------
int main()
//--------
{
	// move semantics 의 활용 예제 - modern C++의 함수 인자 전달
	STRING s[] { "333", "55555", "1", "4444", "22" };
	
	// std::sort();					
	// std::ranges::sort();		// 두 코드는 서로 다르지만 move 를 이해하는 코드들이다.

	관찰 = true;
	std::sort(begin(s), end(s), []( const STRING& a, const STRING& b ) { 
		return a.length() > b.length();
		});
	관찰 = false;

	for ( const STRING& str : s )
		cout << str << '\n';
	
	//save("main.cpp");
}