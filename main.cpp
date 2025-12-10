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
#include <chrono>
#include <thread>
#include "save.h"

using namespace std;


// 시험문제 클래스 계층도 - 컴퓨터 세상에 살고 있는 몬스터들
// TM - 컴퓨터를 시간을 멈추는 몬스터
// SM - 화면에 글씨를 쓰는 몬스터
// 
//					Monster
//
//			TM			SM			???? (본인이 추가해야 할 수도)
// 

class Monster {
public:
	Monster() : id(++gid) {}
	virtual void special() const = 0; // 순수 가상 함수 - Base에 Abstract가 가능하도록

protected:
	int id;								// 몬스터 고유 번호
	static int gid;
};

int Monster::gid = 0;
default_random_engine dre{ 20251215 };
uniform_int_distribution uidMS{ 1, 200 };
uniform_int_distribution uidNUM{ 1, 60 };
uniform_int_distribution<int> uidC{ 'a', 'z' };

// Time Monster
class TM : public Monster {
public:
	// 컴퓨터 시간을 ms 밀리초 동안 멈추는 스페셜 기술
	virtual void special() const override {
		cout << id << ", cpu 정지 - " << ms << "ms" << endl;
		this_thread::sleep_for(chrono::milliseconds(ms));
	}
private:
	int ms { uidMS(dre) }; // 밀리초
};

// Screen Monster
class SM : public Monster {
public:
	// num개의 랜덤 소문자['a', 'z']를 화면에 출력하는 스페셜 기술
	virtual void special() const override { 
		cout << id << ", SM - ";
		for (int i = 0; i < num; ++i) 
			cout << static_cast<char>(uidC(dre));
		cout << endl;
	}
private:
	int num { uidNUM(dre) };
};

//--------
int main()
//--------
{
	SM s[10];
	TM t[5];

	for (const SM& mon : s)
		mon.special();

	for (const TM& mon : t)
		mon.special();

	// 위 코드가 다형성을 구현한 것은 아니다.

	save("main.cpp");
}