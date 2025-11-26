// ----------------------------------------------------------------------
// 12.15 월요일(15주 1일) - 기말시험(다형성)
// ----------------------------------------------------------------------
// class 간의 관계 - 상속(Inheritance)
// ----------------------------------------------------------------------

#include <iostream>
#include <string>

#include "save.h"

using namespace std;

class A {
	// B b;					// A has-a B
};

class B : A {				// B is-a A
};

class Animal { };
class Dog : Animal { };		// Dog is-a Animal


//--------
int main()
//--------
{
	
	save("main.cpp");
}