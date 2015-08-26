#include <iostream>
using namespace std;

void foo(int&) { cout << "int&" << endl; }
void foo(int&&){ cout << "int&&" << endl; }

template<typename T> void Call(T&& a)
{
	// T&& �� int&&�� �����Ǿ a ��ü�� lvalue�̴�.
	// ��, "�̸��� ������ rvalue reference�� lvalue�̴�"

	// �Ʒ� �ǹ�ó�� �ؾ� �մϴ�.
	/*
	if (is_rvalue_reference<T&&>::value)
		foo(static_cast<T&&>(a));
	foo(a);
	*/
	foo(forward<T&&>(a)); // forward�� ���� if��ó�� �Ǿ� �ֽ��ϴ�.
}

int main()
{
	int n = 10;
	Call(n);  // 1
	Call(10); // 1
}