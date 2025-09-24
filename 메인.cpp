//--------------------------------------------------------------------
// 두 변수의 값을 교환하라
// -> pointer, reference --> 원격 메모리를 조작할 수 있는 도구
//--------------------------------------------------------------------

#include <iostream>
#include "save.h"

//void change(int& x, int& y)
//{
//	int temp = x;
//	x = y;
//	y = temp;
//}

void change(int*, int*); // 선언은 헤더 파일에서.

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
	int a { 1 }, b { 2 };

	// 여기에서 a와 b의 값을 서로 바꾸는 코딩을 하라. (직접)
	change(&a, &b); // change 함수로 jump한다. 실제로 cpu에겐 jump 명령어가 존재한다.

	std::cout << a << ", " << b << '\n'; // 2, 1이 출력되어야 한다.

	save("메인.cpp");
}