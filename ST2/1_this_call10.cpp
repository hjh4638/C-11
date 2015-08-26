#include <iostream>
using namespace std;

//��� �Լ��� �ּҸ� ���� �� �ִ� ����
// C, C++ : ���������δ� ����.
//C++11:function<> ��� �Լ��� �ּҸ� ���� �� �ִ�.

class Dialog
{
public:
	void Close()
	{
		cout << "Dialog Closed" << endl;
	}
};

void foo(){ cout << "foo" << endl; }
void goo(int a) { cout << "goo : " << a << endl; }
void hoo(int a, int b){ cout << "hoo : " << a << b << endl; }

#include <functional>
int main(){
	function<void()> f = &foo;
	f();

	f = bind(&goo, 5);
	f();//goo(5)
	Dialog dlg;
	f = bind(&Dialog::Close, &dlg);
	f();
	f = bind(&hoo, 1, 2);
	f();
	/*f = &goo;
	f();
	f = &hoo;
	f();
	f = &Dialog::Close;
	f();*/
}