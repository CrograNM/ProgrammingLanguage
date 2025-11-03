// -------------------------------------------------------------------
// 12.15 월요일(15주 1일) - 기말시험(다형성)
// -------------------------------------------------------------------
// 사용자 정의 자료형 - 기말시험 문제는 다 알려주고 시험본다 (다형성-polymorphism)
// -------------------------------------------------------------------

#include <iostream>
#include <string>
#include "save.h"

using namespace std;

class Dog { 
private:	//---> 이거 숨어있음. access modifier - class의 default 접근 지정자
public:		
protected:

public : 
	void bark() { 
		cout << "멍멍!" << endl; 
	}
};

//--------
int main()
//--------
{
	Dog dog;
	dog.bark();
	save("main.cpp");
}
