//--------------------------------------------------------------------
// 10. 27 월요일 - 중간시험  
//--------------------------------------------------------------------
// fstream
//--------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include "save.h"
using namespace std;

// [문제] 파일 "main.cpp"의 소문자를 대문자로 바꿔서 저장한 파일 "대문자.cpp"를 만들어라.
// 힌트 : 소문자를 대문자로 만드려면 toupper 함수를 사용하면 된다. (static_cast 필요)

//--------
int main()
//--------
{
	save("main.cpp");

	ifstream in { "main.cpp" };
	if (not in) {
		cout << "파일 읽기 실패" << endl;
		return 1;
	}
	ofstream out { "대문자.cpp" };
	char c;

	in >> noskipws; // 공백 문자도 읽기 위해 noskipws 설정. (white space를 건너뛰지 않음)
	while (in >> c) {
		out << static_cast<char>(toupper(c));
	}
}
