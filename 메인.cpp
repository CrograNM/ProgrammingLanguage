//--------------------------------------------------------------------
// 두 변수의 값을 교환하라
// -> pointer, reference --> 원격 메모리를 조작할 수 있는 도구
//--------------------------------------------------------------------

#include <iostream>
#include <random>
#include <print>
#include "save.h"

void change(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

// [문제] 랜덤값(0~99'999)을 갖는 int 10'000개를 만들어라.
// 오름차순으로 정렬하라.
// 정렬 결과를 화면에 출력하라.

std::default_random_engine dre { std::random_device()() };
std::uniform_int_distribution uid { 0, 99999 };

//--------
int main()
//--------
{
	const int SIZE { 10'000 };

	int a[SIZE];
	for (int& num : a) {
		num = uid(dre);
	}

	// [문제] a의 값을 오름차순으로 정렬하시오
	// 버블정렬

	for (int i = 1; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE - i; ++j)
		{
			if (a[j] > a[j + 1])
				change(&a[j], &a[j + 1]);
		}
	}
	
	for (int num : a) {
		std::print("{:6}", num);
	}
	std::cout << '\n';

	save("메인.cpp");
}
