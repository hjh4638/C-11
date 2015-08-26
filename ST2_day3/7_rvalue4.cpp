#include <iostream>
using namespace std;

struct Point
{
	int x, y;
};

Point p;
Point foo(){ return p; }

int main()
{
	int n = 10;

	// &		: lvalue 만 가르킨다
	// const &  : lvalue 와 rvalue를 모두 가르킨다.
	// &&		: rvalue 만 가르킨다
	const int& r1 = n;
	const int& r2 = 10;

	int&& r3 = 10; // ok !! rvalue 전용 참조
	int&& r4 = n;  // error

	Point&& r5 = foo(); // ok... 임시객체도 rvalue 이다.
						// 이 순간 임시객체의 수명이 연장된다.
						// r5를 선언한 블럭이 끝날때까지 살아 있다.
	
	const Point& r6 = foo(); // 이순간도 수명은 연장되지만
							// 상수 객체인 상태로만 사용해야 한다
	cout << r1 << endl << r2 << endl;
}