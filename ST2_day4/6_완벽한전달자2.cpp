#include <iostream>
using namespace std;

void foo(int a){ cout << "foo" << endl; }
void goo(int& a){ cout << "goo" << endl; a = 20; }

// 해결책 1. 함수 오버로딩
//			인자가 한개인 함수의 완벽한 전달자 => 2개의 HowLong
//				   10개인 함수의 완벽한 전달자 => 1024개의 HowLong

template<typename F, typename T> void HowLong(F f, T& a)
{
	f(a);
}

template<typename F, typename T> void HowLong(F f, const T& a)
{
	f(a);
}

int main()
{
	int n = 0;

	HowLong(foo, 0);
	HowLong(goo, n);

	cout << n << endl; // 20
}

/*
int main()
{
int n = 0;
foo(0);
goo(n);
cout << n << endl;
}
*/