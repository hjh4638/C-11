#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

//C의 스레드 개념을 C++로 캡슐화 해봅시다.
// 아래 클래스를 라이브러리 내부 클래스 라고 생각합니다.
class Thread{
public:
	void Create(){ 
		CreateThread(0, 0, _threadMain, this, 0, 0); 
	}
	//스레드함수
	//핵심 1. C의 callback 함수는 객체 지향으로 디자인 될때 static 멤버함수가 되어야 한다.
	//핵심 2. static 멤버에는 this가 없으므로 가상함수나, 멤버 data에 접근할 수 없다..
	//다양한 기법으로 this를 사용할 수 있게 하는 것이 편리하다.!!
	static DWORD __stdcall _threadMain(void* p){
		//결국 p가 this이므로 캐스팅 해서 사용합니다.
		Thread* self = static_cast<Thread*>(p);
		//다시 가상함수 호출
		self->threadMain();//this->threadMain()
		//즉 threadMain(this)가 되어야한다.
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
	CreateThread(0, 0, foo, "A", 0, 0);//스레드를 만드는 함수
	_getch();
}