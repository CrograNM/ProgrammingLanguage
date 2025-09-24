//--------------------------------------------------------------------
// 두 변수의 값을 교환하라
// -> pointer, reference --> 원격 메모리를 조작할 수 있는 도구
//--------------------------------------------------------------------

#include <iostream>
#include "save.h"

void change(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

//--------
int main()		
//--------
{
	int a[] { 3, 9, 1, 4, 2, 0, 8, 5, 7, 6 };

	// [문제] a의 값을 오름차순으로 정렬하시오
	// 버블정렬

	for (int i = 1; i < 10; ++i)
	{
		for (int j = 0; j < 10 - i; ++j)
		{
			if (a[j] < a[j + 1])
				change(&a[j], &a[j + 1]);
		}
	}
	
	for (int num : a) {
		std::cout << num << ' ';
	}
	std::cout << '\n';

	save("메인.cpp");
}