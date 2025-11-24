//-------------------------------------------------------------
// STRING : std::string을 흉내낸 클래스
// cpp에는 클래스를 정의한다.
// 
// 2025. 11. 5
// 2025. 11. 12 필요할 때만 관찰메시지를 출력한다.
// 2025. 11. 17 friend 연산자 함수 추가
// 2025. 11. 24 6개 special function 모두 구현
//-------------------------------------------------------------

#include <iostream>
#include <print>
#include "STRING.h"

unsigned STRING::gid { 0 };

// 2025. 11. 12 필요할 때만 관찰메시지를 출력한다.
bool 관찰 { false };

STRING::STRING() 
	: id { ++gid }
{ 
	if (관찰)
		std::println("[{:5}] 생성    , 내주소:{:14}, 개수:{:<3}, 글주소:{:14}",
				id, (void*)this, len, (void*)p);
}

STRING::~STRING() 
{ 
	if (관찰)
		std::println("[{:5}] 소멸    , 내주소:{:14}, 개수:{:<3}, 글주소:{:14}",
				 id, (void*)this, len, (void*)p);

	// 객체가 소멸되기 전에 정리할 것이 있다면 여기서...
	delete[] p;
}

STRING::STRING(const char* name)
	: id { ++gid }
{
	len = (unsigned)strlen(name);

	p = new char[len];
	// 저장은 memcpy로 한다
	memcpy(p, name, len);	// DMA - 초고속 전송 (Direct Memory Access)

	if (관찰)
		std::println("[{:5}] 생성(*) , 내주소:{:14}, 개수:{:<3}, 글주소:{:14}",
				 id, (void*)this, len, (void*)p);
}

// 2025. 11. 10 복사생성자
STRING::STRING(const STRING& other)
	: id { ++gid }
{
	len = other.len;

	p = new char[len];
	memcpy(p, other.p, len);

	if (관찰)
		std::println("[{:5}] 복사생성, 내주소:{:14}, 개수:{:<3}, 글주소:{:14}",
				 id, (void*)this, len, (void*)p);
}

// 2025. 11. 10 복사할당연산자
STRING& STRING::operator=(const STRING& other)
{
	if (this == &other)	// 자기 자신 할당 방지
		return *this;

	delete[] p;

	len = other.len;

	p = new char[len];
	memcpy(p, other.p, len);

	if (관찰)
		std::println("[{:5}] 복사할당, 내주소:{:14}, 개수:{:<3}, 글주소:{:14}",
				 id, (void*)this, len, (void*)p);

	return *this;
}

// 2025. 11. 24 이동생성자
STRING::STRING(STRING&& other) // && : lvalue --> rvalue
	: id { ++gid }
{
	len = other.len;
	p = other.p;

	// other는 xvalue가 된다.
	// xvalue를 재사용하게 된다면 Valid but unspecified 상태 (유효하지만 지정되지 않은 상태)가 된다.
	// 안전을 위해 other의 멤버들을 초기화한다.
	other.len = 0;		
	other.p = nullptr;
	if (관찰)
		std::println("[{:5}] 이동생성, 내주소:{:14}, 개수:{:<3}, 글주소:{:14}",
				 id, (void*)this, len, (void*)p);
}

// 2025. 11. 24 이동할당연산자
STRING& STRING::operator=(STRING&& other)
{
	if (this == &other)	// 자기 자신 할당 방지
		return *this;

	delete[] p;			// 내 자원을 돌려준다.

	len = other.len;
	p = other.p;

	other.len = 0;
	other.p = nullptr;

	if (관찰)
		std::println("[{:5}] 이동할당, 내주소:{:14}, 개수:{:<3}, 글주소:{:14}",
				 id, (void*)this, len, (void*)p);

	return *this;
}

// 연산자 오버로딩 함수들
// 2025. 11. 12
STRING STRING::operator+( const STRING& rhs )
{
	STRING temp;
	temp.len = len + rhs.len;

	// 메모리 할당
	temp.p = new char[temp.len];

	// 메모리에 내 글자를 복사
	memcpy(temp.p, p, len);

	// 이어서 메모리에 rhs 글자를 복사
	memcpy(temp.p + len, rhs.p, rhs.len);

	return temp;
}
// 2025. 11. 19 - subscript operator
char STRING::operator[]( int idx ) const
{
	return p[idx];
}
char& STRING::operator[]( int idx ) 
{ 
	return p[idx];
}

unsigned STRING::length() const
{
	return len;
}

void STRING::show() const
{
	for (int i=0; i < len; ++i)
		std::cout << p[i];
	std::cout << std::endl;
}

// 클래스의 전역 연산자 오버로딩 함수는 friend로 선언한다. (선언할 때만 friend)
// 2025. 11. 17
STRING operator+(const char* str, const STRING& rhs)
{
	STRING temp;
	unsigned str_len = (unsigned)strlen(str);
	temp.len = str_len + rhs.len;					// 인자들의 길이를 합하여 temp의 길이 계산
	temp.p = new char[temp.len];					// temp 메모리를 길이만큼 확보
	memcpy(temp.p, str, str_len);					// temp 메모리에 왼쪽인자 복사
	memcpy(temp.p + str_len, rhs.p, rhs.len);	   	// temp 메모리에 rhs 이어 붙임
	return temp;
}
std::ostream& operator<<(std::ostream& os, const STRING& rhs)
{
	for (int i = 0; i < rhs.len; ++i)
		os << rhs.p[i];
	
	return os;
}