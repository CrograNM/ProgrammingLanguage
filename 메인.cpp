//--------------------------------------------------------------------
// 두 변수의 값을 교환하라
// -> pointer, reference --> 원격 메모리를 조작할 수 있는 도구
//--------------------------------------------------------------------
// 포인터 - 어떤 지역에서 다른 지역에 있는 메모리를 access 할 때 사용
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


// [문제] 랜덤값(0~99'999)을 갖는 int 100'000개를 만들어라.
// 오름차순으로 정렬하라.
// 정렬 결과를 한 줄(80글자)에 10개씩 화면에 출력하라.


// ===== 교수님 정답 ======


std::default_random_engine dre { std::random_device()() };
std::uniform_int_distribution uid { 0, 99999 };

const int SIZE { 10'0000 }; 
// const : 읽기만 가능하게 만드는 자격 부여 (Read Only)

//--------
int main()
//--------
{

	int a[SIZE];
	for (int i = 0; i < SIZE; ++i) {
		a[i] = uid(dre);
	}

	// [문제] a의 값을 오름차순으로 정렬하시오
	// 버블정렬

	for (int i = 0; i < SIZE - 1; ++i)
	{
		for (int j = 0; j < SIZE - 1 - i; ++j)
		{
			if (a[j] > a[j + 1])
				change(&a[j], &a[j + 1]);
		}
	}
	
	for (int num : a) {
		std::print("{:8}", num);
	}
	std::cout << '\n';

	save("메인.cpp");
}
