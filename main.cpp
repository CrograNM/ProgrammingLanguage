//--------------------------------------------------------------------
// 10. 27 월요일 - 중간시험  
//--------------------------------------------------------------------
// fstream
//--------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <print>
#include "save.h"
using namespace std;

// [문제] 파일 "2025 2학기 프로그래밍언어 강의저장.txt"에 있는 소문자를 세서 다음과 같이 출력하시오.
// a - 2000	(예시)
// b - 800
// 중간 생략
// z - 50
// 힌트: 어떤 char가 소문자인지는 islower 함수로 알 수 있다.

//--------
int main()
//--------
{
	save("main.cpp");

	ifstream in { "2025 2학기 프로그래밍언어 강의저장.txt" };
	if (not in) {
		print("파일을 열 수 없습니다.");
		return 20251020;
	}

	unsigned counts[26] {};	// int 키워드 딱히 안붙여도 자동으로 (unsigned) int 배열로 인식
	char ch;

	while (in >> ch) {
		if (islower(ch)) {
			++counts[ch - 'a'];
		}
	}

	for (int i = 0; i < 26; ++i) {
		cout << static_cast<char>(i + 'a') << " - " << counts[i] << endl;
	}
}
