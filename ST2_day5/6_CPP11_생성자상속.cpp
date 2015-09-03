#include <iostream>
using namespace std;

class Base
{
public:
	void foo(int a)			{ cout << "int"		 << endl; }
	void foo(int a, int b)	{ cout << "int, int" << endl; }
};
class Derived : public Base
{
public:
	// �ڽĿ� ���� ������ �θ��� �Լ��� ����ϰ� �ʹٸ�
	using Base::foo;

	// �ڽ��� foo��� �̸��� ����ϸ�
	// �θ� �ִ� ��� foo �Լ��� ��������. (Hidden) ��� ����!
	void foo(double){ cout << "double" << endl; }
};

int main()
{
	Derived d;
	// �������� ���� ���� �� ������ ��� ������.
	d.foo(1);		// 1. double
	d.foo(1, 2);	// 2. error
	d.foo(3.4);		// 3. double
}