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
	// 자식에 의해 가려진 부모의 함수를 사용하고 싶다면
	using Base::foo;

	// 자식이 foo라는 이름을 사용하면
	// 부모에 있는 모든 foo 함수는 가려진다. (Hidden) 사용 못함!
	void foo(double){ cout << "double" << endl; }
};

int main()
{
	Derived d;
	// 실행하지 말고 다음 중 에러를 모두 고르세요.
	d.foo(1);		// 1. double
	d.foo(1, 2);	// 2. error
	d.foo(3.4);		// 3. double
}