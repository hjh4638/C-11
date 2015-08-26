#include <iostream>
using namespace std;

template<typename T> class my_reference_wrapper
{
	T* obj; 
public:
	my_reference_wrapper(T& r) : obj(&r){}
	operator T&(){ return *obj; }
};

// �Ϻ��� ������ 1�� �ҽ� �����ؿ似��.


void foo(int a){ cout << "foo" << endl; }
void goo(int& a){ cout << "goo" << endl; a = 20; }

template<typename F, typename T>
void HowLong(F f, T a)
{
	f(a);
}


int main()
{
	int n = 0;
	HowLong(foo, 0);
	//HowLong(goo, n);

	// n�� ������ ������ʹٸ� �̵������� ������ ����Ѵ�.
	my_reference_wrapper<int> r1 = n;
	HowLong(goo, r1);
	cout << n << endl; // 20
}
