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
void foo(Point p){}

int main()
{
	Point p;
	foo(p);

	// 값타입의 함수 인자로 전달하기 위한 객체라면 임시객체가 좋다.
	foo(Point());
}