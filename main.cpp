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
#include <fstream>
#include "save.h"

using namespace std;

//---------------------------------------------------------------------------------------
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
	virtual ~Monster() {
		cout << id << " 몬스터 소멸" << endl;
	}

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
	~TM() {
		cout << "TM 소멸" << endl;
	}

	// 컴퓨터 시간을 ms 밀리초 동안 멈추는 스페셜 기술
	virtual void special() const override {
		cout << id << ", cpu 정지 - " << ms << "ms" << endl;
		// this_thread::sleep_for(chrono::milliseconds(ms));
	}

	int getMS() const { return ms; }
private:
	int ms { uidMS(dre) }; // 밀리초
};

// Screen Monster
class SM : public Monster {
public:
	~SM() {
		cout << "SM 소멸" << endl;
	}

	// num개의 랜덤 소문자['a', 'z']를 화면에 출력하는 스페셜 기술
	virtual void special() const override { 
		cout << id << ", SM - ";
		for (int i = 0; i < num; ++i) 
			cout << static_cast<char>(uidC(dre));
		cout << endl;
	}

	int getNum() const { return num; }
private:
	int num { uidNUM(dre) };
};

// New Monster
class NM : public Monster {
public:
	~NM() {
		cout << "NM 소멸" << endl;
	}

	virtual void special() const override {
		cout << id << ", 새로운 몬스터!!!" << endl;
	}
};

//---------------------------------------------------------------------------------------

uniform_int_distribution uid{ 1, 1000 };
int MS기준오름차순(const void* a, const void* b)
{
	const TM* tma = *(const TM**)a;
	const TM* tmb = *(const TM**)b;
	return tma->getMS() - tmb->getMS();
}
int num기준오름차순(const void* a, const void* b)
{
	const SM* sma = *(const SM**)a;
	const SM* smb = *(const SM**)b;
	return sma->getNum() - smb->getNum();
}

//--------
int main()
//--------
{
	// 예상 몬스터 파일 
	{
		ofstream out{ "monster.txt" };
		const int mCount = 10;
		out << mCount << ' ';
		for (int i = 0; i < mCount; ++i) {
			out << uid(dre) << ' ';
		}
	}

	// 몬스터 파일 읽기
	ifstream in{ "monster.txt" };
	if (!in) {
		cout << "몬스터 파일 열기 실패!" << endl;
		return 1;
	}

	int n;
	in >> n; // 전체 몬스터 수
	cout << "\n=== 몬스터 " << n << "마리 생성 ===" << endl;

	Monster** 몬스터들 = new Monster*[n]; // 다형성 배열
	for (int i = 0; i < n; ++i) {
		int t;
		in >> t;
		switch (t % 3) {
		case 0:
			몬스터들[i] = new TM;
			break;
		case 1:
			몬스터들[i] = new SM;
			break;
		case 2:
			몬스터들[i] = new NM;
			break;
		}
	}

	cout << "\n=== 몬스터들 ===" << endl;
	for (int i = 0; i < n; ++i) {
		몬스터들[i]->special(); // 다형성 호출
	}

	// TM 몬스터들을 ms 기준 오름차순으로 정렬했을 때 정렬한 결과를 화면에 출력하라.
	cout << "\n=== TM 몬스터들을 ms 기준 오름차순 정렬 ===" << endl;
	{
		TM** tms = new TM * [n]; // TM 몬스터들만 담을 배열
		int tmCount = 0;
		for (int i = 0; i < n; ++i) {
			TM* tmPtr = dynamic_cast<TM*>(몬스터들[i]);
			if (tmPtr != nullptr) {
				tms[tmCount++] = tmPtr;
			}
		}
		qsort(tms, tmCount, sizeof(TM*), MS기준오름차순);
		for (int i = 0; i < tmCount; ++i) {
			tms[i]->special();
		}
	}

	// TM 중에서 100ms 이상인 몬스터들을 제거하라.
	cout << "\n=== TM 몬스터들 중에서 100ms 이상인 몬스터들 제거 ===" << endl;
	{
		int newCount = 0;
		for (int i = 0; i < n; ++i) {
			TM* tmPtr = dynamic_cast<TM*>(몬스터들[i]);
			if (tmPtr != nullptr && tmPtr->getMS() >= 100) 
				delete 몬스터들[i]; // 메모리 해제
			else 
				몬스터들[newCount++] = 몬스터들[i];
		}
		n = newCount; // 몬스터 수 갱신
	}

	// TM 전부를 제거하라. (dynamic_cast)
	cout << "\n=== TM 몬스터들 전부 제거 ===" << endl;
	{
		int newCount = 0;
		for (int i = 0; i < n; ++i) {
			TM* tmPtr = dynamic_cast<TM*>(몬스터들[i]);
			if (tmPtr != nullptr)
				delete 몬스터들[i]; // 메모리 해제
			else
				몬스터들[newCount++] = 몬스터들[i];
		}
		n = newCount; // 몬스터 수 갱신
	}

	// 남은 몬스터들 스페셜 기술 발동
	cout << "\n=== 몬스터들 ===" << endl;
	for (int i = 0; i < n; ++i) {
		몬스터들[i]->special(); // 다형성 호출
	}

	// NM 전부를 제거하라.
	cout << "\n=== NM 몬스터들 전부 제거 ===" << endl;
	{
		int newCount = 0;
		for (int i = 0; i < n; ++i) {
			NM* nmPtr = dynamic_cast<NM*>(몬스터들[i]);
			if (nmPtr != nullptr)
				delete 몬스터들[i]; // 메모리 해제
			else
				몬스터들[newCount++] = 몬스터들[i];
		}
		n = newCount; // 몬스터 수 갱신
	}

	// 남은 몬스터들 스페셜 기술 발동
	cout << "\n=== 몬스터들 ===" << endl;
	for (int i = 0; i < n; ++i) {
		몬스터들[i]->special(); // 다형성 호출
	}

	// 남은 것들은 전부 SM일텐데, num 기준으로 정렬하라. (contigous임) 
	cout << "\n=== (남은) SM 몬스터들을 num 기준 오름차순 정렬 ===" << endl;
	qsort(몬스터들, n, sizeof(Monster*), num기준오름차순);
	for (int i = 0; i < n; ++i) {
		몬스터들[i]->special(); // 다형성 호출
	}

	cout << "\n=== 모든 몬스터들 소멸 ===" << endl;
	for (int i = 0; i < n; ++i) {
		delete 몬스터들[i];		// 각 동물 객체 메모리 해제
	}
	delete[] 몬스터들;		// 우리 배열 메모리 해제

	// save("main.cpp");
}