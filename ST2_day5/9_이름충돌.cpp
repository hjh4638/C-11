#include <iostream>
using namespace std;

class A
{
public:
	int value;

	A() :value(10){}
};

class B
{
public:
	int value;
	B() :value(20){}
};
class C :public A, public B{};

int main()
{
	C c;
	//cout << c.value << endl; // error
	cout << c.A::value << endl; // ok..
	cout << ((B)c).value << endl; // ok..

}