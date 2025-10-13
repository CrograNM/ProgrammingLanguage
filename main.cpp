//--------------------------------------------------------------------
// 10. 27 월요일 - 중간시험  
//--------------------------------------------------------------------
// 동적할당(Dynamic Allocation) - dynamic은 run-time으로 해석해야 함
//--------------------------------------------------------------------

#include <iostream>
#include "save.h"

using namespace std;


// [문제] 사용자가 원하는 숫자만큼 int를 저장할 메모리를 확보한다.
// 그 메모리를 1부터 시작하는 정수로 채워라.
// 메모리의 합계를 화면에 출력하여라.

//--------
int main()
//--------
{
	cout << "int 몇 개가 필요한가요? ";
	unsigned num; 
	cin >> num;

	int* p;
	p = new int[num]; 

	for (int i = 0; i < num; i++) {
		*(p + i) = i + 1;
	}

	// 합계
	int sum { 0 };
	// for (int val : p)  // ERROR : range-based for문 인데, p는 range가 아니고, 단순 포인터 변수임
	for (int i = 0; i < num; i++) {
		sum += *(p + i);  // 축적 (accumulation)
	}

	cout << "1부터 " << num << "까지의 합계 = " << sum << '\n';
	// endl과 '\n'의 차이는 입력 버퍼를 flush하느냐 마느냐의 차이

	save("main.cpp");
}