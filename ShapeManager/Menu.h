// Menu.h
#pragma once

class Menu {
public:
	// 메인 메뉴 선택
	int selectMainMenu();
	// 도형 종류 선택 (추가/삭제 공용)
	int selectShapeType();
	// 삭제 방식 선택
	int selectDeleteMode();
	// 인덱스 입력 받기
	int inputIndex();
};