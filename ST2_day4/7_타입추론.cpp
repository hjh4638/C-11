#include <iostream>
#include <type_traits>
using namespace std;

template<typename T> void goo(const T& a)
{
	// 아래 표현에서 a의 타입을 "ParamType" 이라고 부릅니다.
	// T : int		a : const int&
}

goo(n); // n을 expr 이라고 부릅니다.
//----------------------------------------------------

// 규칙 1. ParamType이 포인터나 참조가 아닐 때
//	-expr의 const, volatile, reference 속성을 제거하고 전달된다 

template<typename T> void foo(T a)
{
	cout << typeid(T).name() << endl;
}
int main()
{
	int n = 0;
	const int  c = 0;
	const int& r = c;

	// 각각 T는 무슨 타입일까?
	foo(n); // T : int
	foo(c); // T : int
	foo(r); // T : int
}