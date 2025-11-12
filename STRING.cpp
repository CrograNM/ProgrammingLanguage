//-------------------------------------------------------------
// STRING : std::string을 흉내낸 클래스
// cpp에는 클래스를 정의한다.
// 
// 2025. 11. 5
// 2025. 11. 12 필요할 때만 관찰메시지를 출력한다.
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
		std::println("[{:5}] 생성(*), 내주소:{:14}, 개수:{:<3}, 글주소:{:14}",
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