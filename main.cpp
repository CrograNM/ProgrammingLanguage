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

// [문제] class INT를 코딩하여 main()이 의도대로 실행되게 하라.

// Zero Overhead
class INT { 
public:
	INT(int num) : num { num } { }

	INT& operator++() { // 전위증가
		++num;
		return *this;
	}

private :
	int num;

	friend ostream& operator<<(ostream& os, const INT& rhs) {
		os << rhs.num;
		return os;
	}
};

//--------
int main()
//--------
{
	INT a = 100;
	INT b = ++a;
	cout << b << endl;
	
	save("main.cpp");
}