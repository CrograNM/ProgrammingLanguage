//----------------------------------------------------------------------------
// 다형성구현.cpp 
//
// 알아봐야 할 것 
//
//
// - 다형성(Ploymorphism)이란 무엇인가?
// - C++ 언어에서는 어떻게 다형성을 구현하는가?
//
// 2025. 11. 28
//----------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <fstream>

#include "point.h"
#include "triangle.h"
#include "circle.h"
#include "rectangle.h"
#include "ShapeManager.h"
#include "Menu.h"

//-------
int main()
//-------
{
	// 이 프로그램은 프로젝트를 확인하기 위한 것이다.
	// 실습 순서대로 문제를 해결해 보자.
	
	// 1. 관리 클래스를 만듦
	ShapeManager sm(100);	// 최대 100개의 도형을 관리함

    Menu menu; // 메뉴 객체 생성
    while (true) {
        int mainChoice = menu.selectMainMenu();
        if (mainChoice == 0) break; // 종료

        switch (mainChoice) {
        // [추가]
        case 1: 
        {
            int type = menu.selectShapeType();
            Shape* p = nullptr;

            switch (type) {
            // 랜덤한 도형 생성 (기본 생성자)
            case 0: 
            { 
				int randType = rand() % 3; // 0:Triangle, 1:Rectangle, 2:Circle
				type = randType + 1; // 메뉴 선택과 맞추기 위해 +1

                switch (randType) {
                case 0:
                    p = new Triangle();
                    break;
                case 1:
                    p = new Rectangle();
                    break;
                case 2: 
                    p = new Circle();
                    break;
                }
                break;
            }
            // Triangle
            case 1: 
            {
                int x1, y1, x2, y2, x3, y3;
                std::cout << "세 점의 좌표를 입력하세요 (x1 y1 x2 y2 x3 y3): ";
                std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
                p = new Triangle(Point(x1, y1), Point(x2, y2), Point(x3, y3));
                break;
            }
            // Rectangle
            case 2: 
            {
                int rx1, ry1, rx2, ry2;
                std::cout << "두 점의 좌표를 입력하세요 (x1 y1 x2 y2): ";
                std::cin >> rx1 >> ry1 >> rx2 >> ry2;
                p = new Rectangle(Point(rx1, ry1), Point(rx2, ry2));
                break;
            }
            // Circle
            case 3: 
            {
                int cx, cy;
                double radius;
                std::cout << "원의 중심 좌표와 반지름을 입력하세요 (x y radius): ";
                std::cin >> cx >> cy >> radius;
                p = new Circle(Point(cx, cy), radius);
                break;
            }
            default:
                std::cout << "잘못된 도형 타입입니다." << std::endl;
                break;
            }

            if (p) sm.insert(p);
            break;
        }
        // [삭제]
        case 2: 
        {
            int delMode = menu.selectDeleteMode();
            if (delMode == 1) {
                // 인덱스로 삭제
                sm.draw(); // 목록을 먼저 보여주면 좋음
                int idx = menu.inputIndex();
                sm.removeAt(idx);
            } else if (delMode == 2) {
                // 타입으로 전체 삭제
                int type = menu.selectShapeType(); // 어떤 타입 지울지 선택
                sm.removeByType(type);
            }
            break;
        }
        // [그리기]
        case 3: 
        {
            sm.draw();
            break;
        }
        // [파일 저장]
        case 4:
        {
            std::string filename;
            std::cout << "저장할 파일 이름 입력 (예: shapes.txt) : ";
            std::cin >> filename;
            sm.saveToFilename(filename);
            break;
        }
		// [파일 불러오기]
        case 5: 
        {
            std::string filename;
            std::cout << "불러올 파일 이름 입력 : ";
            std::cin >> filename;
            sm.loadFromFilename(filename);
            sm.draw(); // 잘 불러와졌는지 확인
            break;
        }
        }
    }
}