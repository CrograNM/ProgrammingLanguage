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

	// INT(const INT&) = default;				// 이런 식으로 할 수도 있지만, 쓸 이유도 전혀 없음
	// INT& operator=(const INT&) = default;	// 컴파일러가 자동으로 만든다

	// Single-ton 디자인 패턴은 만들지 말고, 전역으로 만드는게 훨씬 낫다

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
	INT b = a;
	cout << b << endl;
	
	save("main.cpp");
}