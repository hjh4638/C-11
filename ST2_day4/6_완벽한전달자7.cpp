#include <iostream>
using namespace std;

void foo(int a){ cout << "foo" << endl; }
void goo(int& a){ cout << "goo" << endl; a = 20; }

// C++11의 universal reference를 사용한 해결책
// int&& : rvalue 레퍼런스 입니다.
// T&& : rvalue 레퍼런스가 아니라
//		 universal reference 또는 forward 레퍼런스라고 합니다.
template<typename F, typename T>
void HowLong(F f, T&& a)
{
	f(a);
}


int main()
{
	int n = 0;

	HowLong(foo, 0);
	HowLong(goo, n);

	cout << n << endl; 
}
