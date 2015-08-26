#include <iostream>
using namespace std;

int x = 10;

int& foo() { return x; }

int main()
{
	auto n = foo(); // 규칙 1. 우변의 타입중
					// const, reference, volatile을 버려라
					// n의 타입은 ???? template과 동일
					// auto : T		n : param		expr : = foo()

	auto& r = foo(); // 규칙 2. 우변의 속성중 레퍼런스무시
					 // auto : T	r : int&		
	n = 20;
	r = 20;

	cout << n << endl;
}