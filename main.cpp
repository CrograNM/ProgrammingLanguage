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
	char x = (*(char*)a);
	char y = (*(char*)b);

	if (x < y)
		return -1;
	else if (x > y)
		return 1;
	return 0; 
}

//--------
int main()
//--------
{
	char pangram[] {"The quick brown fox jumps over the lazy dog"};

	// [문제] pangram을 오름차순으로 qsort를 사용하여 정렬하고 출력하라.

	std::cout << "pangram 이 차지한 메모리 - " << sizeof pangram << " 바이트\n";

	qsort(pangram, (sizeof pangram - sizeof(char)) / sizeof(char), 
		  sizeof(char), 방법);

	std::cout << pangram << '\n';

	save("main.cpp");
}