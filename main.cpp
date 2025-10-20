//--------------------------------------------------------------------
// 10. 27 월요일 - 중간시험  
//--------------------------------------------------------------------
// fstream
//--------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include "save.h"
using namespace std;

// [문제] 파일 "main.cpp" 에 모두 몇 개의 단어가 있는지 출력하라
// (단어) 공백으로 분리된 문자집합을 말한다.

//--------
int main()
//--------
{
	save("main.cpp");

	ifstream in { "main.cpp" };
	if (not in) {
		cout << "파일 열기 실패" << endl;
		return 1;
	}
	string word;
	unsigned counts {};

	while (in >> word) {
		++counts;
	}

	cout << "단어 개수: " << counts << endl;
}
