//--------------------------------------------------------------------
// 2025. 3-2. 프로그래밍언어, 9월 15일 월요일 (3주 1일)
//--------------------------------------------------------------------
// 자료형과 변수
//--------------------------------------------------------------------

#include <iostream>
#include <random>
#include <print>
#include "save.h"

// [문제] int값 1000개를 저장할 메모리를 확보하라.
// 각 int값을 random값으로(니멋대로, 임의의 값으로) 채워라.
// 가장 큰 값을 찾아 화면에 출력하라.

std::default_random_engine dre { std::random_device()() };
std::uniform_int_distribution uid { 0, 9999'9999 };

//--------
int main()
//--------
{
	int n[1'000];
	for (int& val : n) {	// range-based for, range-for 루프
		val = uid(dre);
	}
	
	// 줄 맞춰 출력한다. 숫자 하나당 10칸
	for (int val : n) {
		std::print("{:10}", val);
	}
	std::cout << '\n';

	// 가장 큰 값을 찾아 출력한다.
	int maxVal = std::numeric_limits<int>::min();
	for (int val : n) {			// 복잡도 - O(n)
		if (maxVal < val) {
			maxVal = val;
		}
	}
	std::print("가장 큰 값 - {}\n", maxVal);

	save("메인.cpp");
}