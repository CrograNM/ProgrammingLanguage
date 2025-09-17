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
	// 교수님의 정답

	int num[6] {};

	for (int i = 0; i < TestSize; ++i) {
		++num[uid(dre) - 1];
	}
	for (int i = 0; i < 6; ++i) {
		std::println(" {} : {}번 (확률 - {:.2f}%)", i + 1, num[i], num[i] * 100.0 / TestSize);
	}
	
	save("메인.cpp");
}