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

	int counts[26] {};	// a ~ z
	char ch;

	cout << "파일 읽기 시작" << endl;
	// 한글자씩 읽기 위해서는 다음과 같다.
	while (in >> ch) {
		if (islower(ch)) {
			counts[ch - 'a']++;
		}
	}
	cout << "파일 읽기 끝" << endl;

	for (int i = 0; i < 26; ++i) {
		println ("{:c} - {}", 'a' + i, counts[i]); // :c는 문자 출력 형식 지정자
	}
}
