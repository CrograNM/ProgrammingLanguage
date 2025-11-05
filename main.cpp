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

STRING s { "1" };
//--------
int main()
//--------
{
	STRING s[] { "22" };
	unique_ptr<STRING> p { new STRING { "333" } };
	save("main.cpp");
}