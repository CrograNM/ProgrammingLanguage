//--------------------------------------------------------------------
// 10. 27 월요일 - 중간시험  
//--------------------------------------------------------------------
// FSTREAM
//--------------------------------------------------------------------

#INCLUDE <IOSTREAM>
#INCLUDE <FSTREAM>
#INCLUDE "SAVE.H"
USING NAMESPACE STD;

// [문제] 파일 "MAIN.CPP"의 소문자를 대문자로 바꿔서 저장한 파일 "대문자.CPP"를 만들어라.
// 힌트 : 소문자를 대문자로 만드려면 TOUPPER 함수를 사용하면 된다. (STATIC_CAST 필요)

//--------
INT MAIN()
//--------
{
	SAVE("MAIN.CPP");

	IFSTREAM IN { "MAIN.CPP" };
	IF (NOT IN) {
		COUT << "파일 읽기 실패" << ENDL;
		RETURN 1;
	}
	OFSTREAM OUT { "대문자.CPP" };
	CHAR C;

	IN >> NOSKIPWS; // 공백 문자도 읽기 위해 NOSKIPWS 설정. (WHITE SPACE를 건너뛰지 않음)
	WHILE (IN >> C) {
		OUT << STATIC_CAST<CHAR>(TOUPPER(C));
	}
}
