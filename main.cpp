//--------------------------------------------------------------------
// 10. 27 월요일 - 중간시험 
//--------------------------------------------------------------------
// C++에서 포인터 대신 사용할 수 있는 레퍼런스(reference)
//--------------------------------------------------------------------

#include <iostream>
#include "save.h"

// <방법> : qsort가 요구하는 형식에 맞는 비교함수
// 리턴은 반드시 int를 리턴하는 형식으로 약속
// 인자는 const void* 형식의 포인터 2개를 받도록 약속
int 방법(const void* a, const void* b) 
{
	return *(char*)a - *(char*)b; 
	// 양수, 음수, 0을 리턴하는 형식으로 한줄로 작성 가능
	// 내림차순이면 a, b 순서를 바꾸면 됨
}

//--------
int main()
//--------
{
	char pangram[] {"The quick brown fox jumps over the lazy dog"};

	// [문제] pangram을 오름차순으로 qsort를 사용하여 정렬하고 출력하라.

	qsort(pangram, sizeof pangram - 1, 1, 방법);

	// generic function : 어떤 타입이든 다 처리할 수 있는 함수
	// 프로그래밍에서 generic 이란, 타입을 가리지 않고 다 처리할 수 있는 것을 의미

	// C/C++ -> Procedural Programming
	// C with Classes -> C++의 원래 정의 Object Oriented Programming
	
	// C++의 현재 정의
	// Generic Programming Language			
	// Functional Programming Language
	// Meta Programming Language 

	// OOP 와 GP 는 관점이 다르다.

	// qsort는 Generic Programming의 시작점이라고 볼 수 있음.
	// 자료형에 관심이 없는 함수

	std::cout << pangram << '\n';

	save("main.cpp");
}