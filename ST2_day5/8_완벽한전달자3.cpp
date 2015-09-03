#include <iostream>
using namespace std;

int g_x = 0;
int& foo(int a, int& b)
{
	cout << "foo" << endl; b = 10;
	return g_x;
}

// 3. ���ϰ��� �����־�� �Ѵ�.
template<typename F, typename ... Types>
decltype(auto) HowLong(F f, Types&& ... args)
{
	f(args...);
}

int main()
{
	int x = 0;
	auto& r = HowLong(foo, 1, x);
	r = 30;
	cout << g_x << endl; // 30 ���;� �Ѵ�.
}