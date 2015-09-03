#include <iostream>
using namespace std;

int x = 10;

int& foo(){ return x; }

// 완벽한 전달자 함수
template<typename F> decltype(auto) HowLong(F f)
{
	return f();
}

int mian()
{
	auto& n = HowLong(foo);

	n = 20;

	cout << x << endl;
}