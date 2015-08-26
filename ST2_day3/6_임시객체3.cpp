#include <iostream>
using namespace std;

// Point p; => 이름 있는 객체 p, 블럭을 벗어날때 까지 생존
// Point() => 이름 없는 임시객체 생성. 현재 문장에서만 유효..


class Point
{
	int x, y;
public:
	Point(){ cout << "생성자" << endl; }
	~Point(){ cout << "소멸자" << endl; }

	Point(const Point&){ cout << "복사생성자" << endl; }
};

// 함수 인자와 임시객체
// 값타입으로 리턴하는 함수는 임시객체를 만들게 된다.!
void foo(Point p){}

Point foo()
{
	// Point p2;
	cout << "foo" << endl;

	// 리턴용도로만 객체를 만든다면.. 아래처럼 하는 것이 좋다.
	return Point(); //임시객체를 만들면서 리턴!!
					// Return Value Optimization( RVO ) 라고 불리는 기술
					// C++ IDioms

					// 요즘 C++ 컴파일러 : NRVO를 지원 한다.
					// Named RVO
}
int main()
{
	Point p1;
	cout << "AAA" << endl;
	p1 = foo();
	cout << "BBB" << endl;

	// 값타입의 함수 인자로 전달하기 위한 객체라면 임시객체가 좋다.
	//foo(Point());
}

// 실행하지 말고.. 화면 출력 결과 예측해 보세요..
// 1. 생성자 - p1
// 2. AAA
// 3. 생성자 - p2
// 4. foo
// 5. 복사 생성자 - 리턴용 임시객체
// 6. 소멸자 - p2
// 7. 소멸자 - 임시객체용
// 8. BBB
// 9. 소멸자 - p1