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
	//�����Լ��� �ּҸ� ������ ��¥ �ּҰ� �ƴ�
	// �����Լ� table�� �ε���, �� �����Լ��� ������ ������ �˴ϴ�.
	//g++ : 0,1,2,3 ���� ���ڰ� ������ �˴ϴ�.
	//VC++ : �ּҺ���ϰ� �����µ�.. �� �ּҸ� ���󰡸� index�� �ֽ��ϴ�. VC���� Ư¡
	void(Base::*f)() = &Base::goo;
	cout << f << endl;
	printf("%d\n",f);
	Base* p = new Derived;

	(p->*f)();//?
}