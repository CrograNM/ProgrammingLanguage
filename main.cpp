// ----------------------------------------------------------------------
// 12.15 월요일(15주 1일) - 기말시험(다형성)
// ----------------------------------------------------------------------
// class FILE I/O
// class 간의 관계 - 상속
// ----------------------------------------------------------------------

#include <iostream>
#include <string>
#include <algorithm>
#include "save.h"
#include "STRING.h"
using namespace std;

extern bool 관찰; // 관찰하고 싶으면 true로 바꾸자

// 부를 수 있는 것은 함수만이 아니다. -> callable type (부를 수 있는 타입) 

class Dog { 
public:
	bool operator()(const STRING& a, const STRING& b) const{ 
		return a.length() < b.length();
	}
};
//--------
int main()
//--------
{
	STRING s[] { "333", "55555", "1", "4444", "22" };
	
	// () 연산자도 오버로딩 가능하다.
	// 그래서 이런 코딩도 가능하다.
	Dog dog;							// dog를 호출할 수 있다니? -> callable object
	std::sort(begin(s), end(s), dog);
	//qsort(s, 5, sizeof(STRING), dog); // 얘는 안된다.
	
	// () 연산자 오버로딩 함수는 함수객체(function object)라고 부른다.

	for ( const STRING& str : s )
		cout << str << '\n';
	
	(*save)("main.cpp");
	// (*함수이름) : 함수 포인터 (함수의 주소를 담는 변수), 얘를 호출하면 함수가 실행된다.
}