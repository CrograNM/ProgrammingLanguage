// ----------------------------------------------------------------------
// 12.15 월요일(15주 1일) - 기말시험(다형성)
// ----------------------------------------------------------------------
// class FILE I/O
// class 간의 관계 - 상속
// ----------------------------------------------------------------------

#include <iostream>
#include <string>
#include <random>
#include <print>
#include <fstream>
#include "save.h"
#include "STRING.h"
using namespace std;

extern bool 관찰; // 관찰하고 싶으면 true로 바꾸자

// [문제] main이 의도한대로 실행되도록 class Dog를 코딩하라.
// class Dog {
// private:
//		int id;				// id는 [1, 10'0000]의 랜덤 int값으로 생성
//		STRING name;		// name은 [10, 60]의 랜덤 길이를 갖는다
//							// name은 ['a', 'z']의 랜덤 소문자로 생성된다
// }
// 
// class STRING은 외부에서 구입한 class라서 수정할 수 없다.

default_random_engine dre { random_device{}() };
uniform_int_distribution uid_id { 1, 100'000 };
uniform_int_distribution uid_len { 10, 60 };
uniform_int_distribution<int> uid_char { 'a', 'z' };	// <int> 명시적으로 적어주기

class Dog {
public:
	Dog()
	{
		id = uid_id(dre);

		int len = uid_len(dre);
		char* p = new char[len + 1];
		for (int i = 0; i < len; ++i)
			p[i] = (char)uid_char(dre);
		p[len] = '\0';
		STRING temp = { p };
		delete[] p;

		name = move(temp);	// 이동할당
	}

private:
	int id;
	STRING name;

public:
	friend ostream& operator<<(ostream& os, const Dog& dog) { 
		os << dog.id << "    " << dog.name;
		return os; 
	}
};
//--------
int main()
//--------
{
	ofstream out { "개천마리.txt" };

	Dog dogs[1000];

	for (const Dog& dog : dogs)
		out << dog << endl;	

	save("main.cpp");
}