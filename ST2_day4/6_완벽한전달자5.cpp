#include <iostream>
using namespace std;

template<typename T> class my_reference_wrapper
{
	T* obj;
public:
	my_reference_wrapper(T& r) : obj(&r){}
	operator T&(){ return *obj; }
};

// Ŭ���� ���ø��� �Ͻ��� ���� �߷��� �Ұ����ؼ� �׻� ����� ���Դϴ�.
// �Ͻ��� ���� �߷��� ������ �Լ� ���ø����� Helper�� �����
// ���� ���ϴ�.
template<typename T> 
my_reference_wrapper<T> xref(T& a)
{
	return my_reference_wrapper<T>(a);
}

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

	goo(n); // goo�� ���� ���

//	my_reference_wrapper<int> r1 = n;
//	HowLong(goo, r1);

	// �ӽð�ü�� ���� ����
	HowLong(goo, xref(n));

	cout << n << endl; // 20
}

//template<typename T> T square(T a){ reutnr a*a; }
//
//// ������ ������� ?
//square(3);		//1 ���� ���δ� - �Ͻ��� �߷�
//square<int>(3);	//2 ����� ���� - ����� �߷�
//
//
//// Ŭ���� ���ø��� �Ͻ��� ����ȯ �ȵ�
//list<int> s(10, 3); // 10���� 3����!!!