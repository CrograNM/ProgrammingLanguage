//----------------------------------------------------------------------------
// ShapeManager.cpp 
//----------------------------------------------------------------------------
#include <iostream>
#include <print>
#include "shapeManager.h"

#include "Triangle.h"   // dynamic_cast를 위해 필요
#include "Rectangle.h"
#include "Circle.h"

using namespace std;

ShapeManager::ShapeManager(int n)
{
	nShape = 0;
	capacity = n;
	shapes = new Shape * [capacity];
}

ShapeManager::~ShapeManager()
{
	cout << "ShapeManager 소멸자 호출\n";

	// 1. 관리하던 모든 개별 도형 객체를 먼저 삭제 (소멸자 호출 유도)
	for (int i = 0; i < nShape; ++i) {
		delete shapes[i];
	}

	// 2. 포인터 배열(컨테이너) 삭제
	delete[] shapes;
};

void ShapeManager::insert(Shape* a)
{
	shapes[nShape] = a;
	nShape++;
};

void ShapeManager::draw() const
{
	cout << "------------------------------------------" << '\n';
	cout << "관리하는 모든 도형을 그립니다" << '\n';
	cout << "최대 " << capacity << "개의 도형을 담을 수 있습니다" << '\n';
	cout << "모두 " << nShape << "개의 도형이 있습니다" << '\n';
	cout << "------------------------------------------" << '\n' << '\n';
	for (int i = 0; i < nShape; ++i) {
		std::print("[{:3}] ", i);	// cout << "[" << i << "] ";
		shapes[i]->draw();
	}
	cout << '\n';
	cout << "------------------------------------------" << '\n';
	cout << "그리기를 마칩니다" << '\n';
	cout << "------------------------------------------" << '\n' << '\n';
};

// 1. 특정 인덱스 삭제
void ShapeManager::removeAt(int index)
{
    if (index < 0 || index >= nShape) {
        cout << "[오류] 존재하지 않는 번호입니다.\n";
        return;
    }

    // 1. 메모리 해제
    delete shapes[index];

    // 2. 배열 당기기 (Shifting)
    // 삭제된 위치(i)부터 끝까지, 뒤의 요소(i+1)를 앞으로 가져옴
    for (int i = index; i < nShape - 1; ++i) {
        shapes[i] = shapes[i + 1];
    }

    // 3. 개수 줄이고, 마지막 포인터 초기화 (안전장치)
    nShape--;
    shapes[nShape] = nullptr;

    cout << "[" << index << "]번 도형이 삭제되었습니다.\n";
}

// 2. 특정 타입 일괄 삭제
void ShapeManager::removeByType(int type)
{
    int deletedCount = 0;

    // 배열을 순회하며 조건에 맞는 것을 찾음
    // -> 앞에서부터 지우면 인덱스가 밀려서 건너뛰게 됨.
    // --> 뒤에서부터 검사하면 인덱스 문제 없이 안전하게 삭제 가능.
    for (int i = nShape - 1; i >= 0; --i) {
        bool isTarget = false;

        // dynamic_cast를 사용하여 실제 객체 타입 확인
        // (type == 1: Triangle, 2: Rectangle, 3: Circle)
        if (type == 1 && dynamic_cast<Triangle*>(shapes[i])) isTarget = true;
        else if (type == 2 && dynamic_cast<Rectangle*>(shapes[i])) isTarget = true;
        else if (type == 3 && dynamic_cast<Circle*>(shapes[i])) isTarget = true;

        if (isTarget) {
            removeAt(i); // 위에서 만든 함수 재사용
            deletedCount++;
        }
    }

    if (deletedCount == 0)
        cout << "해당 타입의 도형이 없습니다.\n";
    else
        cout << "총 " << deletedCount << "개의 도형을 삭제했습니다.\n";
}