#include <iostream>
using namespace std;

int g_x = 0;
int& foo(int a, int& b)
{
	cout << "foo" << endl; b = 10; 
	return g_x; 
}

// 2. 참조인자를 가지는 함수도 생각해야 한다. - universal reference
//	  가변인자를 universal reference로 받아야 한다.
template<typename F, typename ... Types>
void HowLong(F f, Types&& ... args)
{
	f(args...);
}

int main()
{
	int x = 0;
	HowLong(foo, 1, x);

	cout << x << endl; // 10 나와야 한다.
}