#include <iostream>
using namespace std;

void foo(int n)		{ cout << "foo" << endl; }
void goo(char* p)	{ cout << "goo" << endl; }

void hoo(int a, int b){ cout << "hoo" << endl; }
void koo(){ cout << "koo" << endl; }
// �Լ��� ����Ǵ� �ð��� Ȯ���ϴ� ������ ����� ���ô�.
template<typename F, typename ... Types>
void HowLong(F f, Types ... args)
{
	// �ð� ����
	f(args...);
	// �ð� ���� �� ���
}
int main()
{
//	foo(0);
//	goo(0);
	HowLong(foo, 0);
//	HowLong(goo, 0);

	HowLong(hoo, 1, 2);
	HowLong(koo);
}