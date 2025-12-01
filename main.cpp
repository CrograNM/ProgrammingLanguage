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
	Animal(const char* n) : name(n) { }

	void move() { 
		cout << name << " - 움직이는 중" << endl;
	}

protected:	// 상속 때문에 만들 수 밖에 없었던 접근 지정자
	string name;
};

class Dog : public Animal {
private:
	int speed = 10;

public:
	Dog(const char* n) : Animal(n) {
	}

	// member function overriding -> 오버로딩과 차이점은? 
	void move() {
		cout << name << " 난 달리기 선수 - " << speed << endl;
	}
};

//--------
int main()
//--------
{
	Dog dog { "코코" };
	dog.move();		// 코코 난 달리기 선수 - speed

	save("main.cpp");
}