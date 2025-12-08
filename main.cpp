// ----------------------------------------------------------------------
// 12.15 월요일(15주 1일) - 기말시험(다형성)
// ----------------------------------------------------------------------
// class 간의 관계 - 상속(Inheritance)
// - 코드 재활용
// - 다형성(Polymorphism) 구현하려고
//		-> One Interface, Multiple Behaviors
// ----------------------------------------------------------------------

#include <iostream>
#include <string>
#include <random>
#include "save.h"

using namespace std;

class Animal {
public:
	Animal() = default;
	Animal(const char* n) : name{ n } { }

	virtual void move() const { 
		cout << name << " - 움직이는 중" << endl;
	}

	virtual ~Animal() = default;

protected:	// 상속 때문에 만들 수 밖에 없었던 접근 지정자
	string name;
};

class Dog : public Animal {
public:
	Dog() = default;
	Dog(const char* n) : Animal(n) {
	}

	// member function overriding -> 오버로딩과 차이점은? 
	void move() const override {
		cout << name << "Dog 달린다" << endl;
	}

	int getSpeed() const {
		return speed;
	}
private:
	int speed { };
};

class Bird : public Animal {
public:
	void move() const override {
		cout << name << "Bird 난다" << endl;
	}
};

default_random_engine dre { 20251208 };
uniform_int_distribution<int> uid { 0, 1 };

// [문제] 동물농장 주인이다.
// 사용자가 원하는 수 num마리 만큼 동물들을 관리할 수 있다.
// 랜덤값 0이면 Dog, 1이면 Bird로 농장을 채운다.
// 모든 동물들의 move()를 호출하여 다형성이 구현됨을 관찰한다.

//--------
int main()
//--------
{
	cout << "관리할 동물 수는?";
	int num;
	cin >> num;

	Animal** 우리 = new Animal * [num];	// Animal** : Animal* 배열의 포인터(주소)
	for (int i = 0; i < num; ++i) { 
		if (0 == uid(dre)) {
			우리[i] = new Dog;
		}
		else {
			우리[i] = new Bird;
		}
	}
	
	for ( int i = 0; i < num; ++i) 
		우리[i]->move();		 // 다형성 구현 확인
	
	save("main.cpp");
}