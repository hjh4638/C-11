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
	//void foo(const PINT& a) // 가상함수를 재정의 하고 싶습니다. 채우세요.
	void foo(int* const& a)
	{
		cout << "2" << endl;
	}
};

int main()
{
	Base<int*>* p = new Derived;
	p->foo(0); // 자식 foo 호출되어야 합니다.
}

*/

int main()
{
	cout << typeid("aaa").name() << endl;
}