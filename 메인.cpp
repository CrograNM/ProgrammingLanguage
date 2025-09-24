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

	// [문제] a의 값 중에서 가장 큰 수를 오른쪽으로 옮겨라
	for (int i = 0; i < 9; ++i) {
		if (a[i] > a[i + 1]) 
			change(&a[i], &a[i + 1]);

		for (int num : a) {
			std::cout << num << ' ';
		}
		std::cout << '\n';
	}

	save("메인.cpp");
}