#include <iostream>
using namespace std;

class Test{
	int data;
public:
	void f1(){ cout << "f1" << endl; }
	int f2(){ cout << "f2" << endl; return 0; }
	int f3(){ cout << "f3" << endl; return data; }//this->data

	//아래 코드는 왜 만들었을까요?
	//NULL 객체에 대해서 함수를 호출해도 죽지 않게 하기 위해
	int call_f3(){ return this ? f3() : 0; }

	virtual void f4(){}
};

int main(){
	Test* p = 0;//메모리 할당에 실패해서 0이 나왔다고 가정합니다.

	p->f1();//어떻게 될까요? 실행하지 말고 생각해보세요.
	//f1(p), f1(0)
	p->f2();//ok
	p->f3();//

	p->call_f3();
	p->f4();//될까요? 0번지에 가상함수 테이블이 있다고 생각하게 된다.!! 실행시간 error
}