#define _CRT_SECURE_NO_WARNINGS

//-------------------------------------------------------------
// save.cpp - 한 학기 강의를 잘 저장하는 함수
//                                                  2025. 3. 13
//-------------------------------------------------------------

#include <string_view> // 필요한 부분만 인클루드 해야함
#include <fstream>
#include <iostream>
#include <filesystem>
#include <chrono>

void save(std::string_view fileName)
{
	// 1. 인자로 전달된 fileName을 읽기 모드로 연다
	std::ifstream in{ fileName.data() }; // RAII*** cpp 핵심 기능

	if (not in) {
		std::cout << fileName << "을 열 수 없습니다." << std::endl;
		exit(20250310);
	}

	// 저장했다는 것을 화면에 표시하자.
	std::cout << fileName << "(" << std::filesystem::file_size(fileName)
		<< " bytes) 저장하였습니다." << std::endl;

	// 2. 쓰기 모드로 저장할 파일을 연다.(덧붙이기 모드로)
	std::ofstream out{ "2025 2학기 프로그래밍언어 강의저장.txt", std::ios::app };

	// 시간을 기록하자
	auto now = std::chrono::system_clock::now();			// epoch로 부터 경과된 tick 개수를 얻는다
	auto utc = std::chrono::system_clock::to_time_t(now);	// UTC
	auto lt = std::localtime(&utc);							// 지역 시간으로 변경 (OS 기준)
	auto old = out.imbue(std::locale("ko_KR"));				// 스트림의 지역을 변경

	// std::cout << "현재 시간 - " << std::put_time(lt, "%c %A") << '\n';

	out << '\n' << '\n';
	out << "=========================================" << '\n';
	out << "저장한 시간: " << std::put_time(lt, "%c %A") << '\n';
	out << "=========================================" << '\n';
	out << '\n';
	out.imbue(old);											// 변경 이전으로 복원

	// 3. 파일을 읽어서 저장할 파일에 덧붙인다.
	std::copy(std::istreambuf_iterator{ in }, {}, std::ostreambuf_iterator{ out });
};