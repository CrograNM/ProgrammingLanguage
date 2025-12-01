// Menu.cpp
#include <iostream>
#include "Menu.h"
using namespace std;

int Menu::selectMainMenu()
{
	int choice;
	cout << "\n=== [ 도형 관리 프로그램 ] ===\n";
	cout << "1. 도형 추가\n";
	cout << "2. 도형 삭제\n";
	cout << "3. 전체 그리기\n";
	cout << "4. 파일로 저장\n";
	cout << "5. 파일에서 불러오기\n";
	cout << "0. 종료\n";
	cout << ">> 선택: ";
	cin >> choice;
	return choice;
}

int Menu::selectShapeType()
{
	int choice;
	cout << "\n--- 도형 종류 선택 ---\n";
	cout << "1. 삼각형\n";
	cout << "2. 사각형\n";
	cout << "3. 원\n";
	cout << "4. 선\n";
	cout << ">> 선택: ";
	cin >> choice;
	return choice;
}

int Menu::selectDeleteMode()
{
	int choice;
	cout << "\n--- 삭제 모드 선택 ---\n";
	cout << "1. 특정 번호(Index)로 하나만 삭제\n";
	cout << "2. 특정 도형 종류(Type) 전체 삭제\n";
	cout << ">> 선택: ";
	cin >> choice;
	return choice;
}

int Menu::inputIndex()
{
	int idx;
	cout << ">> 삭제할 도형 번호 입력: ";
	cin >> idx;
	return idx;
}