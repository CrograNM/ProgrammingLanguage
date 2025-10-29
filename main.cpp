// -------------------------------------------------------------------
// 12.15 월요일(15주 1일) - 기말시험(다형성)
// -------------------------------------------------------------------
// 사용자 정의 자료형 - 기말시험 문제는 다 알려주고 시험본다 (다형성-polymorphism)
// -------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include "save.h"

using namespace std;

struct Dog { 
	string name;

	void show() const // 중요 : const 멤버 함수 // const, volatile ==> cv qualifiers : 자격을 부여한다
	{
		cout << name << " 입니다." << endl;
	}
};

//--------
int main()
//--------
{
	save("main.cpp");

	int n { 100 };
	Dog dog { "댕댕이" };
	dog.show();
}