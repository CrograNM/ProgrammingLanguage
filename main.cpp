// ----------------------------------------------------------------------
// 12.15 월요일(15주 1일) - 기말시험(다형성)
// ----------------------------------------------------------------------
// class 간의 관계 - 상속(Inheritance)
// - 코드 재활용
// - 다형성(Polymorphism) 구현하려고
// ----------------------------------------------------------------------

#include <iostream>
#include <string>

#include "save.h"

using namespace std;

class Animal {
private:
	string name;
};

class Dog : public Animal {
private:
	int speed;
};

//--------
int main()
//--------
{
	// Dog dog { "코코" };
	// cout << dog << endl; // 출력 - 나는 코코입니다.

	save("main.cpp");
}