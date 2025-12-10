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
	// 이것은 기말시험문제 예시이다.

	// 강의시간에 만든 클래스 계층을 사용한다.
	// 새롭게 추가한 몬스터가 있을 수 있다.
	// NewMon

	// 이 시험 문제는 몬스터들을 관리하는 코드이다.
	// 관리할 몬스터의 수는 시험 시 제공 (입력, 파일)
	// 5 10 12 323 23 12 4
	// 여기서 5는 전체 몬스터 수 나머지 숫자를 3으로 나눈 나머지에 따라 
	// 0 - TM 
	// 1 - SM
	// 2 - NewMon을 관리하는 Monster에 추가한다.

	// (기본)
	// - 메모리 그림 그리기
	// 관리하는 첫 몬스터를 정확하게 그림으로 그려라.
	// 관련된 메모리를 정확하게 크기와 이름을 표시해야 한다.
	
	// (도전)
	// TM 몬스터들을 ms 기준 오름차순으로 정렬했을 때 정렬한 결과를 화면에 출력하라.
	
	// TM 중에서 100ms 이상인 몬스터들을 제거하라.
	
	// TM 전부를 제거하라. (dynamic_cast)
	
	// (도전)
	// 남은 것들은 전부 SM일텐데, num 기준으로 정렬하라. (contigous임) 
	
	// (큰 배점)
	// 현재 num 마리 Monster를 관리 중인데 2배를 더 관리하고 싶다.
	// 예시 코드가 문제없게 실행되게 코딩하라.	
	
	// (0점 방지)
	// 메모리 다 정리하고 끝내도록 코딩하라.		

	save("main.cpp");
}