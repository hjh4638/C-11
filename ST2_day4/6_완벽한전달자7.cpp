#include <iostream>
using namespace std;

void foo(int a){ cout << "foo" << endl; }
void goo(int& a){ cout << "goo" << endl; a = 20; }

// C++11�� universal reference�� ����� �ذ�å
// int&& : rvalue ���۷��� �Դϴ�.
// T&& : rvalue ���۷����� �ƴ϶�
//		 universal reference �Ǵ� forward ���۷������ �մϴ�.
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
