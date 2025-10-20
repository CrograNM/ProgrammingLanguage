//--------------------------------------------------------------------
// 10. 27 월요일 - 중간시험  
//--------------------------------------------------------------------
// fstream
//--------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include "save.h"
using namespace std;

// [문제] 파일 "main.cpp"에
// 사용자가 입력한 문자가 몇 개나 있는지 알려줘라.
// 이 과정을 영원히 반복할 수 있게 코딩해라.
// 예) 입력 - z
//	   z의 개수 - 1개

//--------
int main()
//--------
{
	save("main.cpp");
	
	char input_ch;	// 사용자 입력 문자
	char ch;		// 파일 검사용 문자
	unsigned count {};

	while (true) {
		cout << "입력 - ";
		cin >> input_ch;

		ifstream in { "main.cpp" };
		if (not in) {
			cout << "파일 오픈 실패" << endl;
			return 20251020;
		}

		count = 0;
		while (in >> ch) {
			if (ch == input_ch) {
				++count;
			}
		}
		in.close();
		cout << input_ch << "의 개수 - " << count << "개" << endl;
	}
}
