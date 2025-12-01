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
public:
	void move() { 
		cout << name << "이야 - 움직이니까 동물이다" << endl;
	}

protected:
	string name;
};

class Dog : public Animal {
private:
	int speed = 0;

public:
	Dog(const char* str) { 
		name = str;
	}
};

//--------
int main()
//--------
{
	Dog dog { "코코" };
	dog.move();

	save("main.cpp");
}