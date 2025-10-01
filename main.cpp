//--------------------------------------------------------------------
// 10. 27 월요일 - 중간시험 
//--------------------------------------------------------------------
// C++에서 포인터 대신 사용할 수 있는 레퍼런스(reference)
//--------------------------------------------------------------------

#include <iostream>
#include "save.h"

int LikeThis(const void* a, const void* b);

int LikeThis(const void* a, const void* b)
{
	char x = (*(char*)a);
	char y = (*(char*)b);

	if (x < y)
		return -1;
	else if (x > y)
		return 1;
	return 0; // stable한 sort 에 필요
}

//--------
int main()
//--------
{
	char pangram[] {"The quick brown fox jumps over the lazy dog"};

	// [문제] pangram을 오름차순으로 qsort를 사용하여 정렬하고 출력하라.

	qsort(pangram, sizeof(pangram)-1, sizeof(char), LikeThis);

	for (char c : pangram)
		std::cout << c;
	std::cout << '\n';

	save("main.cpp");
}