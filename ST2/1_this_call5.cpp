#include <iostream>
using namespace std;

class Test{
	int data;
public:
	void f1(){ cout << "f1" << endl; }
	int f2(){ cout << "f2" << endl; return 0; }
	int f3(){ cout << "f3" << endl; return data; }//this->data

	//�Ʒ� �ڵ�� �� ����������?
	//NULL ��ü�� ���ؼ� �Լ��� ȣ���ص� ���� �ʰ� �ϱ� ����
	int call_f3(){ return this ? f3() : 0; }

	virtual void f4(){}
};

int main(){
	Test* p = 0;//�޸� �Ҵ翡 �����ؼ� 0�� ���Դٰ� �����մϴ�.

	p->f1();//��� �ɱ��? �������� ���� �����غ�����.
	//f1(p), f1(0)
	p->f2();//ok
	p->f3();//

	p->call_f3();
	p->f4();//�ɱ��? 0������ �����Լ� ���̺��� �ִٰ� �����ϰ� �ȴ�.!! ����ð� error
}