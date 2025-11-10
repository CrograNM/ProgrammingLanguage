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

//--------
int main()
//--------
{
	STRING s[] { "1", "22", "333" };

	for (STRING& str : s)		// 이렇게 하면 복사생성자가 호출되어 임시객체가 만들어짐.
		str.show();				// Range-based for를 쓸 때는 레퍼런스(&)를 붙여주어 복사생성자가 호출되지 않게 하는 것이 좋다.
								// for (STRING& str : s)

	// 포인터 레퍼런스는 복사하지 않겠다는 의미. 원격에서 직접 접근할 수 있는 유용한 도구인거다.
	// 읽기 전용으로 쓸 때는 const도 붙여준다.		( const : 읽기만 하겠다는 한정사 )
	for (const STRING& str : s)				// C++ const consistency 
		str.show();
	
	// const, volatile - cv qualifiers

	save("main.cpp");
}