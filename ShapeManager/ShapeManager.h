#pragma once

//----------------------------------------------------------------------------
// ShapeManager.h	여러 개의 도형을 관리하는 클래스
//
//--------------------------------------------------------
// Shape* (부모 클래스의 *)로 전체 도형을 관리하는 것이 핵심 
//--------------------------------------------------------
// 
// 2025. 11. 28
//----------------------------------------------------------------------------

#include "shape.h"

class ShapeManager {
	int nShape;			   // 현재 관리 중인 도형의 개수
	int capacity;		   // 확보한 메모리에 담을 수 있는 도형의 최대 개수
	Shape** shapes;		   // 도형의 포인터들을 담을 수 있는 메모리
public:
	explicit ShapeManager(int n);	// 담을 수 있는 도형의 개수를 생성자에 전달
									// explicit 사용법을 알아보자

	~ShapeManager();
	ShapeManager(const ShapeManager&) = default;

	void insert(Shape*);			// 도형을 추가하는 함수
	void draw() const;				// 전체 도형을 그리는 함수

	// [추가된 기능]
	void removeAt(int index);      // 특정 번호 삭제
	void removeByType(int type);   // 1:Triangle, 2:Rectangle, 3:Circle (타입별 전체 삭제)

	void saveToFilename(std::string filename);		// 파일로 저장
	void loadFromFilename(std::string filename);	// 파일에서 불러오기
	void clear();                   // 모든 도형 삭제 (로드 전에 기존 도형 삭제용)
};