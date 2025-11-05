//-------------------------------------------------------------
// STRING : std::string을 흉내낸 클래스
// cpp에는 클래스를 정의한다.
// 
// 2025. 11. 5
//-------------------------------------------------------------

#include <iostream>
#include "STRING.h"

STRING::STRING(const char* name)
	: len { (unsigned)strlen(name) }
{
	p = new char[len];
	// 저장은 memcpy로 한다
	memcpy(p, name, len);	// DMA - 초고속 전송 (Direct Memory Access)
}

unsigned STRING::length()
{
	return len;
}
