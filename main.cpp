// ----------------------------------------------------------------------
// 12.15 월요일(15주 1일) - 기말시험(다형성)
// ----------------------------------------------------------------------
// class FILE I/O
// class 간의 관계 - 상속
// ----------------------------------------------------------------------

#include <iostream>
#include <string>
#include <print>
#include <random>

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
uniform_int_distribution<int> uid_id { 1, 100'000 };
uniform_int_distribution<int> uid_len { 10, 60 };
uniform_int_distribution<char> uid_char { 'a', 'z' };

class Dog {
public:
	Dog()
	{
		id = uid_id(dre);

		int len = uid_len(dre);
		char* buf = new char[len + 1]; // +1 for null
		for (int i = 0; i < len; ++i)
			buf[i] = (char)uid_char(dre);
		buf[len] = '\0';
		name = STRING(buf);
		delete[] buf;
	}

private:
	int id;
	STRING name;

public:
	friend ostream& operator<<(ostream& os, const Dog& dog) { 
		std::print("[{:6}] - {}", dog.id, dog.name);
		return os; 
	}
};
//--------
int main()
//--------
{
	Dog dogs[10];

	for (const Dog& dog : dogs)
		cout << dog << endl;		// [id 6글자] - name 포맷으로 출력

	save("main.cpp");
}