#include <iostream>
using namespace std;

struct Point
{
	int x, y;
};

Point p = { 1, 1 };

//Point foo() : 값리턴 - 임시객체 리턴, lvalue가 될 수 없다.
Point& foo() // 참조리턴 - 임시객체 생성안됨. lvalue가 될 수 있다.
{				//		단, 지역변수의 참조는 절대 안된다!!!
	return p;
}

int main()
{
	// 임시객체는 lvalue 가 될 수 없습니다.
	// 아래 코드가 VC++에서는 에러가 없지만 g++ 에서는 컴파일 에러
	foo().x = 10;	// 임시객체.x = 10
	cout << p.x << endl; // 1
}