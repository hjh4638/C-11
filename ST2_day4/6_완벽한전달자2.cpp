#include <iostream>
using namespace std;

void foo(int a){ cout << "foo" << endl; }
void goo(int& a){ cout << "goo" << endl; a = 20; }

// �ذ�å 1. �Լ� �����ε�
//			���ڰ� �Ѱ��� �Լ��� �Ϻ��� ������ => 2���� HowLong
//				   10���� �Լ��� �Ϻ��� ������ => 1024���� HowLong

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