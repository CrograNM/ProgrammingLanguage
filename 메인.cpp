//--------------------------------------------------------------------
// 자료형과 변수
//--------------------------------------------------------------------

#include <iostream>
#include <random>
#include <print>
#include "save.h"

std::default_random_engine dre { std::random_device()() };
std::uniform_int_distribution uid { 1, 6 };

const int TestSize = 100'0000;

// [문제] 주사위를 100만번 던졌다.
// 각 숫자가 나온 횟수(확률)을 계산해서 화면에 출력하라.

//--------
int main()
//--------
{
	int counts[6] = {}; // 0~5 인덱스
	for (int i = 0; i < TestSize; ++i) {
		++counts[uid(dre) - 1];
	}
	for (int i = 0; i < 6; ++i) {
		std::print("{} : {}번 ({:.2f}%)\n", i + 1, counts[i], counts[i] * 100.0 / TestSize);
	}
	
	save("메인.cpp");
}