//--------------------------------------------------------------------
// 10. 27 월요일 - 중간시험  
//--------------------------------------------------------------------
// 사용자 정의 자료형
//--------------------------------------------------------------------

#include <iostream>
#include "save.h"
using namespace std;

const string FILE_NAME = "main.cpp";

//--------
int main()
//--------
{
	save(FILE_NAME);

	struct 인트2개 {
		int a;
		int b;
	};
	
	인트2개 a;
	
	cout << "sizeof(인트2개): " << sizeof(인트2개) << endl;
	cout << "sizeof(a): " << sizeof(a) << endl;
	cout << "typeid(a).name(): " << typeid(a).name() << endl;
}