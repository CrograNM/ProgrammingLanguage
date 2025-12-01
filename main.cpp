// ----------------------------------------------------------------------
// 12.15 월요일(15주 1일) - 기말시험(다형성)
// ----------------------------------------------------------------------
// class 간의 관계 - 상속(Inheritance)
// - 코드 재활용
// - 다형성(Polymorphism) 구현하려고
// ----------------------------------------------------------------------

#include <iostream>
#include <string>
#include <random>

#include "save.h"

using namespace std;

default_random_engine dre { 20251201 };
uniform_int_distribution<int> uid { 1, 10'000 };

class Animal {
public:
	Animal() = default;
	Animal(const char* n) : name(n) { }

	void move() { 
		cout << name << " - 움직이는 중" << endl;
	}

protected:	// 상속 때문에 만들 수 밖에 없었던 접근 지정자
	string name;
};

class Dog : public Animal {
public:
	Dog() = default;
	Dog(const char* n) : Animal(n) {
	}

	// member function overriding -> 오버로딩과 차이점은? 
	void move() {
		cout << name << " 난 달리기 선수 - " << speed << endl;
	}

private:
	int speed { uid(dre) };
};

//--------
int main()
//--------
{
	// [문제] 문제없이 실행되도록 필요한 코드를 추가하고 답지에 추가한 내용을 적어라.
	Dog dogs[1000];				// 여기서 speed 값은 [1, 10'000] 랜덤값으로 설정한다.

	for (const Dog& dog : dogs) { 
		dog.move();
	}

	// speed 기준 오름차순으로 정렬
	// qsort(dogs, 1000, sizeof(Dog), 속도기준오름차순);
	
	// 가장 빠른 dog의 정보를 화면에 출력
	// dogs[999].move();

	// save("main.cpp");
}