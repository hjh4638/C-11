#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

//C�� ������ ������ C++�� ĸ��ȭ �غ��ô�.
// �Ʒ� Ŭ������ ���̺귯�� ���� Ŭ���� ��� �����մϴ�.
class Thread{
public:
	void Create(){ 
		CreateThread(0, 0, _threadMain, this, 0, 0); 
	}
	//�������Լ�
	//�ٽ� 1. C�� callback �Լ��� ��ü �������� ������ �ɶ� static ����Լ��� �Ǿ�� �Ѵ�.
	//�ٽ� 2. static ������� this�� �����Ƿ� �����Լ���, ��� data�� ������ �� ����..
	//�پ��� ������� this�� ����� �� �ְ� �ϴ� ���� ���ϴ�.!!
	static DWORD __stdcall _threadMain(void* p){
		//�ᱹ p�� this�̹Ƿ� ĳ���� �ؼ� ����մϴ�.
		Thread* self = static_cast<Thread*>(p);
		//�ٽ� �����Լ� ȣ��
		self->threadMain();//this->threadMain()
		//�� threadMain(this)�� �Ǿ���Ѵ�.
		return 0;
	}
	virtual void threadMain()//threadMain(Thread* this)
	{}
};
class MyThread : public Thread{
public:
	virtual void threadMain(){ cout << "MyThread" << endl; }
};
DWORD __stdcall foo(void* p){
	cout << "foo" << endl;
	return 0;
}
int main(){
	MyThread t;
	t.Create();
	CreateThread(0, 0, foo, "A", 0, 0);//�����带 ����� �Լ�
	_getch();
}