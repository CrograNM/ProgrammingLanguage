//--------------------------------------------------------------------
// 레퍼런스 - 
//--------------------------------------------------------------------

#include <iostream>
#include "save.h"

//--------
int main()
//--------
{
	int a { 1 }; 
	int& r { a };  

	// [문제] a와 r의 정체를 파악해주세요.

	std::cout << "== a의 정체 ==" << '\n'; 
	std::cout << "a의 메모리 크기 - " << sizeof a << "\n"; 
	std::cout << "a의 메모리 주소 - " << std::addressof(a) << "\n";
	std::cout << "a의 데이터 타입 - " << typeid(a).name() << "\n\n";

	std::cout << "== r의 정체 == " << '\n';
	std::cout << "r의 메모리 크기 - " << sizeof r << "\n";
	std::cout << "r의 메모리 주소 - " << std::addressof(r) << "\n";
	std::cout << "r의 데이터 타입 - " << typeid(r).name() << "\n\n";

	save("메인.cpp");
}
