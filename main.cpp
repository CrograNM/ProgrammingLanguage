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
	
	while (true) {
		cout << "찾으실 문자는? - ";
		char charToFind;
		cin >> charToFind;

		ifstream in { "main.cpp" };	// RAII - 지역에서 열어서 자동으로 사라짐.
		if (not in) {
			cout << "파일 열기 실패" << endl;
			return 1;
		}

		char c;
		unsigned cnt { 0 };
		while (in >> c) {
			if (charToFind == c) {
				++cnt;
			}
		}
		cout << charToFind << "의 개수 - " << cnt << endl;

		//in.close(); // RAII - 지역에서 열어서 자동으로 사라짐. 즉, 안써도 됨.
	}
}
