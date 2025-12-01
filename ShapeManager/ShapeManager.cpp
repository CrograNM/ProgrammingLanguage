//----------------------------------------------------------------------------
// ShapeManager.cpp 
//----------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <print>
#include "shapeManager.h"


#include "Triangle.h"   // dynamic_cast를 위해 필요
#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"

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
	// 1. 공간이 꽉 찼는지 확인
	if (nShape >= capacity) {
		// 2. 기존 크기의 2배로 확장
		int newCapacity = capacity * 2;

		// 만약 capacity가 0이었다면 2배 해도 0이므로 기본값 설정 (안전장치)
		if (newCapacity == 0) newCapacity = 10;

		Shape** newShapes = new Shape * [newCapacity];

		// 디버깅용 메시지 (확인용)
		std::cout << ">> 저장 공간이 부족하여 크기를 늘립니다. ("
			<< capacity << " -> " << newCapacity << ")\n";

		// 3. 기존 데이터 복사
		for (int i = 0; i < nShape; ++i) {
			newShapes[i] = shapes[i];
		}

		// 4. 기존 배열 삭제
		// 배열 안의 도형 객체 말고 그 주소를 담고 있던 '배열 틀'만 지우기
		delete[] shapes;

		// 5. 멤버 변수가 새 배열을 가리키게 함
		shapes = newShapes;
		capacity = newCapacity;
	}

	// 6. 넉넉해진 공간에 도형 추가
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
    cout << "그리기 끝\n";
	cout << "------------------------------------------" << '\n';
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
		else if (type == 4 && dynamic_cast<Line*>(shapes[i])) isTarget = true;

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


// 기존 도형 모두 삭제 (로드 전 초기화 용도)
void ShapeManager::clear()
{
	for (int i = 0; i < nShape; ++i) {
		delete shapes[i];
	}
	nShape = 0;
}

void ShapeManager::saveToFilename(std::string filename)
{
	std::ofstream fout { filename }; // 파일 열기 (쓰기 모드)

	if (!fout.is_open()) {
		std::cout << "파일을 열 수 없습니다.\n";
		return;
	}

	fout << nShape << std::endl; // 1. 전체 도형 개수 저장

	for (int i = 0; i < nShape; ++i) {
		// 2. 도형의 타입 ID 저장 (이게 있어야 나중에 복구할 때 뭔지 알 수 있음)
		fout << shapes[i]->getID() << " ";

		// 3. 도형별 데이터 저장
		shapes[i]->save(fout);
	}

	fout.close();
	std::cout << filename << "에 저장을 완료했습니다.\n";
}

void ShapeManager::loadFromFilename(std::string filename)
{
	std::ifstream fin(filename); // 파일 열기 (읽기 모드)

	if (!fin.is_open()) {
		std::cout << "파일을 찾을 수 없습니다.\n";
		return;
	}

	// 기존 데이터 비우기 (새로 불러오니까)
	clear();

	int count = 0;
	fin >> count; // 1. 전체 개수 읽기

	for (int i = 0; i < count; ++i) {
		int type = 0;
		fin >> type; // 2. 도형 타입 읽기

		Shape* p = nullptr;

		// 타입에 맞춰 빈 객체 생성 (Factory Pattern 기초)
		if (type == 1) p = new Triangle();
		else if (type == 2) p = new Rectangle();
		else if (type == 3) p = new Circle();
		else if (type == 4) p = new Line();

		if (p != nullptr) {
			p->load(fin); // 3. 해당 객체의 데이터 채우기
			insert(p);    // 매니저에 등록
		}
	}

	fin.close();
	std::cout << "파일에서 " << nShape << "개의 도형을 읽어왔습니다.\n";
}