// ----------------------------------------------------------------------
// 12.15 월요일(15주 1일) - 기말시험(다형성)
// ----------------------------------------------------------------------
// class 간의 관계 - 상속(Inheritance)
// - 코드 재활용
// - 다형성(Polymorphism) 구현하려고
// ----------------------------------------------------------------------

#include <iostream>
#include <string>

#include "save.h"

using namespace std;

class StarString : public string { 
private:
	friend ostream& operator<<(ostream& os, const StarString& ss) { 
		for ( const char& c : ss) {
			if (isdigit(c)) 
				os << '*';
			else 
				os << c;
		}
		return os;
	}
};

//--------
int main()
//--------
{
	string str { "2025년 11월 26일 - 상속하면 뭐가 좋은가" };

	// [과제] str을 화면에 출력하는데 숫자는 '*'로 바꿔라.
	StarString ss { str };
	
	cout << ss << endl;

	save("main.cpp");
}