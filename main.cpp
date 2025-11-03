// ----------------------------------------------------------------------
// 12.15 월요일(15주 1일) - 기말시험(다형성)
// ----------------------------------------------------------------------
// 표준 std::string과 유사한 STRING을 만들어 보며 special 함수들을 알아본다
// ----------------------------------------------------------------------

#include <iostream>
#include <string>
#include "save.h"
using namespace std;

class STRING {
public:
	// []는 *로 collapse 된다.
	STRING(const char* name) : len { (unsigned)strlen(name) }
	{
		p = new char[len];
		// 저장은 memcpy로 한다
		memcpy(p, name, len);	// DMA - 초고속 전송 (Direct Memory Access)
	}

	unsigned length() const
	{
		return len;
	}

private:
	unsigned len {};
	char* p;
};

//--------
int main()
//--------
{
	save("main.cpp");

	STRING s { "2025년 11월 3일 클래스의 스페셜함수를 알아보기 시작한다" };

	cout << "글자 수 - " << s.length() << endl;
	//cout << "글 내용 - " << s << endl;
}
