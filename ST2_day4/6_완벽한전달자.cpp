#include <iostream>
using namespace std;

void foo(int a){ cout << "foo" << endl; }
void goo(int& a){ cout << "goo" << endl; a = 20; }

template<typename F, typename T>
void HowLong(F f, const T& a)
{
	f(a);
}


int main()
{
	int n = 0;

	// �Ʒ� 2���� ��츦 ��� �Ϻ��ϰ� �����ϴ� HowLong�� 
	// ���� �� ������?
	// ����� �����ϰ�, ������ �����ϰ�
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