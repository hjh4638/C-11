#include <iostream>
using namespace std;

class Base{
public:
	virtual void goo(){ cout << "Base goo" << endl; }
	virtual void foo(){ cout << "Base foo" << endl; }
	//virtual void foo() = 0;
};
class Derived :public Base{
public:
	virtual void foo(){ cout << "Derived foo" << endl; }
};
int main(){
	//가상함수의 주소를 꺼내면 진짜 주소가 아닌
	// 가상함수 table의 인덱스, 즉 가상함수의 순서가 나오게 됩니다.
	//g++ : 0,1,2,3 등의 숫자가 나오게 됩니다.
	//VC++ : 주소비슷하게 나오는데.. 그 주소를 따라가면 index가 있습니다. VC만의 특징
	void(Base::*f)() = &Base::goo;
	cout << f << endl;
	printf("%d\n",f);
	Base* p = new Derived;

	(p->*f)();//?
}