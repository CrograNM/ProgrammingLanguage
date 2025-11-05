//-------------------------------------------------------------
// STRING : std::string을 흉내낸 클래스
// 헤더에는 클래스의 선언부분을 코딩한다.
// 
// 2025. 11. 5
//-------------------------------------------------------------
#pragma once

class STRING {
public:
	STRING(const char* name);
	unsigned length();

private:
	unsigned len {};
	char* p {};
};
