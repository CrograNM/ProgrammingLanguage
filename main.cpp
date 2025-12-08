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
	virtual ~Animal()
	{	// 길잡이 : virtual destructor
		cout << "Animal 소멸" << endl;
	}

	virtual void move() const = 0; // pure virtual function
};

class Dog : public Animal {
public:
	~Dog () {
		cout << "Dog 소멸" << endl;
	}

	virtual void move() const override {
		cout << "Dog 달린다" << endl;
	}
};

class Bird : public Animal {
public:
	~Bird () {
		cout << "Bird 소멸" << endl;
	}

	virtual void move() const override {
		cout << "Bird 난다" << endl;
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
	cout << "관리할 동물 수는? ";
	int num;
	cin >> num;

	Animal** 우리 = new Animal * [num];	// Animal** : Animal* 배열의 포인터(주소)
	for (int i = 0; i < num; ++i) {
		if (0 == uid(dre)) {
			우리[i] = new Dog;
		} else {
			우리[i] = new Bird;
		}
	}

	// [문제] 동물농장 사업이 너무 잘된다. 농장을 2배로 늘리려 한다.
	// 우리에 있는 모든 동물을 새 우리로 모두 옮겨라.
	// 그리고 Dog를 num + 1 번째 동물로 채워 넣어라.
	// 이때 다형성 코드는 변하지 않아야 한다.

	Animal** 새집 = new Animal * [num * 2];
	for (int i = 0; i < num; ++i) {
		새집[i] = 우리[i];	// 기존 동물들 옮기기 (포인터 복사)
	}
	delete[] 우리;			// 기존 우리 메모리 해제
	우리 = 새집;				// 우리 포인터를 새집으로 변경

	우리[num] = new Dog;		// 새로운 Dog 추가
	num += 1;

	for (int i = 0; i < num; ++i) {
		우리[i]->move();		// 다형성 구현 확인
	}
	
	// [문제] 끝나기 전에 메모리를 확실하게 정리하였나?
	// 당신은 어떻게 확인하였나요?

	for (int i = 0; i < num; ++i) {
		delete 우리[i];		// 각 동물 객체 메모리 해제
	}
	delete[] 우리;		// 우리 배열 메모리 해제

	save("main.cpp");
}