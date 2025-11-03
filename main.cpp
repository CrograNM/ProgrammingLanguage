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
public:
	Dog() { // special function - default constructor -> default ctor (creator 줄여서)
		name = "디폴트";
		cout << "생성자(default) 호출되었다. " << endl;
	}
	// Dog(string) 생성자
	Dog(string this_name) : name { this_name } {
		cout << "생성자(string) 호출되었다. " << endl;
	}

	~Dog() { // special function - destructor
		// 소멸자 - 객체가 소멸될 때 호출되는 함수
		// 소멸자는 단 하나만 존재한다.
		cout << "소멸자가 호출되었다." << endl;
	}

	// 생성자와 소멸자는 메모리를 색칠하는거지, 직접 메모리를 해제하는건 아님
		
	void bark() {
		cout << name << " 입니다멍" << endl;
	}

// 캡슐화, 추상화, 정보은닉 
private: // access modifier - class의 default (private)
	string name;
};

// Dog* p { new Dog {"코코"s} }; -> 소멸자 호출 안됨 -> 메모리 누수

//--------
int main()
//--------
{
	save("main.cpp");
	cout << "------------ 메인 시작 ------------" << endl;
	unique_ptr<Dog[]> p{ // 이름을 지정하지 않으면 자동 소멸 - RAII를 구현하는 객체
		new Dog[3] { "코코"s }  
	}; 
	cout << "------------ 메인 끝 -------------" << endl;
}
// 이름쓰면 메인 이후에 소멸자 호출됨
