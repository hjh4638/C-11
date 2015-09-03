#include <iostream>
using namespace std;

int g_x = 0;
int& foo(int a, int& b)
{
	cout << "foo" << endl; b = 10; 
	return g_x; 
}

// 2. �������ڸ� ������ �Լ��� �����ؾ� �Ѵ�. - universal reference
//	  �������ڸ� universal reference�� �޾ƾ� �Ѵ�.
template<typename F, typename ... Types>
void HowLong(F f, Types&& ... args)
{
	f(args...);
}

int main()
{
	int x = 0;
	HowLong(foo, 1, x);

	cout << x << endl; // 10 ���;� �Ѵ�.
}