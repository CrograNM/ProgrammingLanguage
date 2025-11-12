// ----------------------------------------------------------------------
// 12.15 월요일(15주 1일) - 기말시험(다형성)
// ----------------------------------------------------------------------
// 표준 std::string과 유사한 STRING을 만들어 보며 special 함수들을 알아본다
// ----------------------------------------------------------------------

#include <iostream>
#include <string>
#include "save.h"
#include "STRING.h"
using namespace std;

int 이렇게(const void* a, const void* b);

extern bool 관찰; // 관찰하고 싶으면 true로 바꾸자

//--------
int main()
//--------
{
	STRING s[] { "333", "1", "55555", "22", "4444" };

	// [문제] s를 길이기준 오름 차순으로 정렬하라

	관찰 = true;
	qsort( s, 5, sizeof(STRING), 이렇게 );
	관찰 = false;

	for (const STRING& str : s)				
		str.show();

	save("main.cpp");
}

int 이렇게(const void* a, const void* b)
{
	const STRING& s = *(STRING*)a;
	const STRING& t = *(STRING*)b;

	if (s.length() < t.length())
		return -1;
	if (s.length() > t.length())
		return 1;
	return 0;
}