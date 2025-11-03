// -------------------------------------------------------------------
// 12.15 월요일(15주 1일) - 기말시험(다형성)
// -------------------------------------------------------------------
// 사용자 정의 자료형 - 기말시험 문제는 다 알려주고 시험본다 (다형성-polymorphism)
// -------------------------------------------------------------------

#include <iostream>
#include <string>
#include "save.h"

using namespace std;

class Dog {
public:
	Dog()
	{ // special function - default constructor -> default ctor (creator 줄여서)
		name = "디폴트";
	}

	// Dog(string) 생성자
	Dog(string this_name) : name { this_name } {
	}
	
	void bark() {
		cout << name << " 입니다멍" << endl;
	}

// 캡슐화, 추상화, 정보은닉 
private: // access modifier - class의 default (private)
	string name;
};

//--------
int main()
//--------
{
	Dog dogs[3] = { string{"코코"}, "보리"s, "콩이"s }; // s: string literal, 연산자 오버로딩
	for ( Dog dog : dogs )
		dog.bark();
	save("main.cpp");
}
