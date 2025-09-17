//--------------------------------------------------------------------
// 2025. 3-2. 프로그래밍언어, 9월 15일 월요일 (3주 1일)
//--------------------------------------------------------------------
// 자료형과 변수
//--------------------------------------------------------------------

#include <iostream>
#include <random>
#include <print>
#include "save.h"

std::default_random_engine dre { std::random_device()() };
std::uniform_int_distribution uid { 0, 1'000 };
const int TestSize = 100;

void findValue(int n[]) {
	int findNum;
	std::cout << "찾을 값을 입력하세요: ";
	std::cin >> findNum;
	bool IsFound = false;
	for (int i = 0; i < TestSize; ++i) {
		if (n[i] == findNum) {
			IsFound = true;
			break;
		}
	}

	if (IsFound) {
		std::cout << findNum << "는(은) 있습니다.\n";
	} else {
		std::cout << findNum << "는(은) 없습니다.\n";
	}
}

//--------
int main()
//--------
{
	int n[TestSize];

	for (int& val : n) {	// range-based for, range-for 루프
		val = uid(dre);
	}

	std::cout << "전체 값 출력" << '\n';
	
	// 줄 맞춰 출력한다. 숫자 하나당 10칸
	for (int i = 0; i < TestSize; ++i) {
		std::print("[{:8}] ", n[i]);
	}
	std::cout << '\n';

	// [문제] 사용자가 찾기를 원하는 int 값을 입력받아
	// 있으면 있다, 없으면 없다 라고 출력하는 코드를 작성하시오.

	while (true) {
		findValue(n);

		std::cout << "계속 하시겠습니까? (1: 예, 0: 아니오): ";
		int cont;
		std::cin >> cont;
		if (cont == 0) break;
	}
	
	save("메인.cpp");
}