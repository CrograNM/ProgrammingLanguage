//--------------------------------------------------------------------
// C++에서 포인터 대신 사용할 수 있는 레퍼런스(reference)
//--------------------------------------------------------------------

#include <iostream>
#include <random>
#include <print>
#include "save.h"

void change(int&, int&); 

void change(int& x, int& y)
{
	int temp { x };
	x = y;
	y = temp;
}


// [문제] 랜덤값(0~99'999)을 갖는 int 100'000개를 만들어라.
// 오름차순으로 정렬하라.
// 정렬 결과를 한 줄(80글자)에 10개씩 화면에 출력하라.


// ===== 교수님 정답 ======


std::default_random_engine dre { std::random_device()() };
std::uniform_int_distribution uid { 0, 99999 };

const int SIZE { 10'000 };

//--------
int main()
//--------
{
	int a[SIZE]; 
	// contiguous memory	(인접한, 공간의 연속)
	// continuous			(연속, 시간)

	for (int i = 0; i < SIZE; ++i) {
		a[i] = uid(dre);
	}

	// [문제] a의 값을 오름차순으로 정렬하시오
	// 정렬 전문 코드에 부탁해서 정렬하면 된다.

	qsort( a, SIZE, sizeof(int), 이렇게);
	// std::sort();
	// std::ranges::sort();

	for (int num : a) {
		std::print("{:8}", num);
	}
	std::cout << '\n';

	save("메인.cpp");
}