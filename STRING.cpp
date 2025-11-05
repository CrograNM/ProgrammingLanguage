//-------------------------------------------------------------
// STRING : std::string을 흉내낸 클래스
// cpp에는 클래스를 정의한다.
// 
// 2025. 11. 5
//-------------------------------------------------------------

#include <iostream>
#include <print>
#include "STRING.h"

unsigned STRING::gid { 0 };

STRING::STRING() 
	: id { ++gid }
{ 
	std::println("[{:5}] 생성    , 내주소:{}", 
				 id, (void*)this);
}

STRING::STRING(const char* name)
	: id { ++gid }
{
	len = (unsigned)strlen(name);

	p = new char[len];
	// 저장은 memcpy로 한다
	memcpy(p, name, len);	// DMA - 초고속 전송 (Direct Memory Access)
}

unsigned STRING::length()
{
	return len;
}

void STRING::show()
{
	for (int i=0; i < len; ++i)
		std::cout << p[i];
	std::cout << std::endl;
}