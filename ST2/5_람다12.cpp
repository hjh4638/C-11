//��� ���� ĸ��
#include <iostream>
using namespace std;

class Test{
	int base;
	int test1;
	int test2;
public:
	Test(int n) :base(100), test1(n), test2(n){}

	void foo(){
		//��� ������ base�� ĸ�� �Ϸ���?
		//auto f = [base](){cout << base << endl; };


		//���� ĸ�Ĵ� �ƴ����� �����͸� ������ �����Ƿ� ���氡��
		// ���� 1. �Ʒ� �ڵ带 ��������� �����Ϸ��� ������ 
		//		Ŭ������ ������ ������.
		auto f = [this](){base = 200; cout << base << endl; 
		cout << test1 << endl;
		cout << test2 << endl;
		};
		f();
	}
};

int main(){
	Test t(20);
	t.foo();
}