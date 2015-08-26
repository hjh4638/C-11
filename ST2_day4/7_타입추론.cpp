#include <iostream>
#include <type_traits>
using namespace std;

template<typename T> void goo(const T& a)
{
	// �Ʒ� ǥ������ a�� Ÿ���� "ParamType" �̶�� �θ��ϴ�.
	// T : int		a : const int&
}

goo(n); // n�� expr �̶�� �θ��ϴ�.
//----------------------------------------------------

// ��Ģ 1. ParamType�� �����ͳ� ������ �ƴ� ��
//	-expr�� const, volatile, reference �Ӽ��� �����ϰ� ���޵ȴ� 

template<typename T> void foo(T a)
{
	cout << typeid(T).name() << endl;
}
int main()
{
	int n = 0;
	const int  c = 0;
	const int& r = c;

	// ���� T�� ���� Ÿ���ϱ�?
	foo(n); // T : int
	foo(c); // T : int
	foo(r); // T : int
}