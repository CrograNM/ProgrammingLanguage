//--------------------------------------------------------------------
// 2025. 3-2. 프로그래밍언어, 9월 10일 수요일 (2주 2일)
//--------------------------------------------------------------------
// 자료형과 변수
//--------------------------------------------------------------------

#include <iostream>
#include "save.h"

// [문제] int값 2개를 입력받아 합계를 알려주는 함수 add를 작성하라.
// 다음 main이 문제없이 실행되어야 한다.

// 함수 선언 - function declaration
int add(int, int);		
int add(int, int);		
int add(int, int);		
int add(int, int);		
int add(int, int);		// 선언은 중복해도 문제가 없다.

// 함수 정의 - function definition
// 정의에 있는 코드는 그대로 메모리에 로드된다.
int add(int num1, int num2)
{
	return num1 + num2;
}

//--------
int main()
//--------
{
	std::cout << "합계를 알려줍니다" << '\n';
	std::cout << "int값 2개를 입력하세요: ";
	int a, b;
	std::cin >> a >> b;

	std::cout << a << " + " << b << " = " << add(a, b) << '\n';

	save("메인.cpp");
}