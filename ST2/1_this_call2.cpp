#include <iostream>
using namespace std;
//1. �Ϲ� �Լ� �����Ϳ� ��� �Լ��� �ּҸ� ���� �� ����. 
// this ������..!!
//2. �Ϲ� �Լ� �����Ϳ� static ��� �Լ��� �ּҸ� ���� �� �ִ�.
//3. ��� �Լ� �����͸� ����� ����ϴ� ���
// void(Dialog::*f)() = &Dialog::Close;

//Dialog dlg;
//(dlg.*f3)();
class Dialog{
public:
	void Close(){ cout << "Dialog Close" << endl; }
};

void foo(){ cout << "foo" << endl; }

int main(){
	void(*f1)() = &foo;//ok
	//void(*f2)() = &Dialog::Close; // ���� ����. �ֳĸ� this�Ķ���� �־

	//��� �Լ� �����͸� ����� ��
	void(Dialog::*f3)() = &Dialog::Close; //ok �ܿ��μ���!

	//f3(); //�̰� �ȵ� this�� ����

	Dialog dlg;
	//dlg.f3();//ok �ᱹ dlg.Close() �� f3(&dlg)
	//�׷��� �� ��� �����Ϸ��� f3�̶�� �����
	//ã�Եȴ�. �׷��� error
	(dlg.*f3)(); //f3�� �Լ��������̹Ƿ� *f3�ϸ� �Լ��� �ȴ�.!
	//.*������ �켱������ �Լ�ȣ��() ���� ������

	Dialog* pDlg = &dlg;

	(pDlg->*f3)();
}