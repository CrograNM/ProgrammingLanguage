//--------------------------------------------------------------------
// 2025. 3-2. 프로그래밍언어, 9월 8일 월요일 (2주 1일)
//--------------------------------------------------------------------
// 자료형과 변수
//--------------------------------------------------------------------

#include <iostream>
#include <bitset>
#include "save.h"

// [실습] 다른 기본 자료형도 지금 한 것과 같이 반복하며 메모리와 친해지자

//--------
int main()
//--------
{
	int n = 0x01020304;
	std::cout << std::bitset<32>(n) << '\n';

	// 메모리가 저장되는 순서는 기계에 따라 다르다
	// 이것을 little endian, big endian이라고 한다.
	// 조금만 설명하자면
	// 0x01020304라는 4바이트 정수를 메모리에 저장할 때
	// little endian은 04 03 02 01 순서로 저장하고
	// big endian은 01 02 03 04 순서로 저장한다.

	int n2 = std::numeric_limits<int>::max();
	std::cout << "int_max : " << n2 << '\n';

	float f = std::numeric_limits<float>::max();
	std::cout << "float_max : " << f << '\n';

	double d = std::numeric_limits<double>::max();
	std::cout << "double_max : " << d << '\n';

	save("메인.cpp");

}