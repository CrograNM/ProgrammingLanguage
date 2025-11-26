// ----------------------------------------------------------------------
// 12.15 월요일(15주 1일) - 기말시험(다형성)
// ----------------------------------------------------------------------
// class FILE I/O
// class 간의 관계 - 상속(Inheritance)
// ----------------------------------------------------------------------

#include <iostream>
#include <string>
#include <random>
#include <print>
#include <fstream>

#include <thread>
#include <chrono>

#include "save.h"
#include "STRING.h"
using namespace std;

extern bool 관찰; // 관찰하고 싶으면 true로 바꾸자

// [문제] 다운받은 파일 "개천마리.txt" 에 class Dog 객체 1000개가 저장되어 있다.
// class Dog {
// private:
//     int id;
//     std::string name;
// }
// 파일에서 Dog 객체 1000개를 읽어 메모리에 저장하라.
// 길이기준 오름차순으로 정렬하라.
// 화면에 id와 name을 출력하라.

class Dog {
public:
	int getLen() const { return name.length(); }

private:
	int id;
	std::string name;

	friend std::istream& operator>>(std::istream& is, Dog& dog) {
		is >> dog.id >> dog.name;
		return is;
	}
	friend std::ostream& operator<< (ostream& os, const Dog& dog) { 
		os << "아이디 - " << dog.id << ", 이름 - " << dog.name;
		return os;
	}
};

int 길기오(const void* a, const void* b)
{
	return ((const Dog*)a)->getLen() - ((const Dog*)b)->getLen();
}

//--------
int main()
//--------
{
	ifstream in { "개천마리.txt" };
	if (!in) {
		cout << "개천마리.txt 파일을 열 수 없습니다." << endl;
		return 20251126;
	}

	Dog dogs[1'000];
	for (Dog& dog : dogs) 
		in >> dog;
	

	// 길이기준 오름차순 정렬(qsort)
	qsort(dogs, 1'000, sizeof(Dog), 길기오);

	for (const Dog& dog : dogs) 
	{
		cout << dog << endl;
		// this_thread::sleep_for();
	}
	
	save("main.cpp");
}