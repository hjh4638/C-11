#include <iostream>
using namespace std;


/*
template<typename T> class Base
{
public:
	void test(){ foo(); }

	virtual void foo(T const& a){ cout << "1" << endl; }
};

typedef int* PINT;
class Derived : public Base < int* >
{
public:
	//void foo(const PINT& a) // �����Լ��� ������ �ϰ� �ͽ��ϴ�. ä�켼��.
	void foo(int* const& a)
	{
		cout << "2" << endl;
	}
};

int main()
{
	Base<int*>* p = new Derived;
	p->foo(0); // �ڽ� foo ȣ��Ǿ�� �մϴ�.
}

*/

int main()
{
	cout << typeid("aaa").name() << endl;
}