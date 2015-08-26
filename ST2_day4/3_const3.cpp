#include <iostream>
using namespace std;

int main()
{
	int n = 10;

	const int* p1 = &n; // p1은 const 아님. p1을 따라가면 const 
	int* const p2 = &n; // p2은 const. p2를 따라가면 const 아님.

	// p1을 가리키는 참조 r1을 만들어 보세요.
	// p2을 가리키는 참조 r2을 만들어 보세요.

	const int*& r1 = p1; // 상수를 가리키는 포인터 참조
	int* const& r2 = p2; // 상수포인터(포인터 자체가 상수)의 참조

	// 힌트 : int의 참조를 int&입니다

}