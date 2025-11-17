//-------------------------------------------------------------
// STRING : std::string을 흉내낸 클래스
// 헤더에는 클래스의 선언부분을 코딩한다.
// 
// 클래스에는 6가지 스페셜함수가 있다.
// 1. STRING()								- default constructor		
// 2. ~STRING()								- destructor
// 
// 3. STRING( const STRING& )				- copy constructor
// 4. STRING& operator=( const STRING& )	- copy assignment operator
// 
// 5. STRING( STRING&& )					- move constructor
// 6. STRING& operator=( STRING&& )			- move assignment operator
// 
// 2025. 11. 5
// - 관찰메시지를 작성하였다.
//-------------------------------------------------------------
#pragma once

class STRING {
public:
	// 스페셜 함수들 자리
	STRING();								// 1. 디폴트 생성자
	~STRING();								// 2. 소멸자 ( ~ : tilde )

	STRING(const char* name);

	STRING(const STRING&);					// 3. 복사생성자		- 2025. 11. 10
	STRING& operator=(const STRING&);		// 4. 복사할당연산자	- 2025. 11. 10

	// 연산자 오버로딩 함수들
	STRING operator+( const STRING& rhs );
	
	// 인터페이스 함수들
	unsigned length() const;			// 2025. 11. 12 const 일관성
	void show() const;					// 2025. 11. 10 const 일관성 (이 함수는 읽기만 할거야, 안심해 라고 약속하는 것)

private:
	unsigned len {};
	char* p {};

	unsigned id;			// 객체에 붙이는 고유번호
	static unsigned gid;	// 클래스에서 선언한 static 멤버

	// 클래스의 전역 연산자 오버로딩 함수는 friend로 선언한다.
	friend STRING operator+(const char*, const STRING&);				// 2025. 11. 17
	friend std::ostream& operator<<(std::ostream&, const STRING&);		// 2025. 11. 17
};
