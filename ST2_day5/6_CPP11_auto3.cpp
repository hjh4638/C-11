#include <iostream>
using namespace std;

int x = 10;

int& foo(){ return x; }

// �Ϻ��� ������ �Լ�
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