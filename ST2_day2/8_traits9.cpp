#include <iostream>
#include <type_traits>
using namespace std;

//traits ����
//1. T�� �Ӽ� ����
template<typename T> void foo(const T& a)
{
	if (is_array<T>::value)
		cout << "�迭, ũ��� " << extent<T, 1>::value << endl;
}

//2. TŸ���� ����
template<typename T> void goo(const T& a)
{
	//typename remove_pointer<T>::type n;
	typename add_pointer<T>::type n;
	cout << typeid(n).name() << endl;
}

int main()
{
	int x[10][20]; foo(x);
	int n;	   goo(&n);
}

//���� 2.
template<typename T> void foo(const T& a)
{
	if (xhas_virtual_function<T>::value) //is_abstract<T>::value
		cout << "�����Լ��� �ֽ��ϴ�" << endl;
}
template<typename T> void goo(const T& a)
{
	typename my_remove_pointer<T>::type n;
}
//if