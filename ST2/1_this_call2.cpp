#include <iostream>
using namespace std;
//1. 일반 함수 포인터에 멤버 함수의 주소를 담을 수 없다. 
// this 때문에..!!
//2. 일반 함수 포인터에 static 멤버 함수의 주소를 담을 수 있다.
//3. 멤버 함수 포인터를 만들고 사용하는 방법
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
	//void(*f2)() = &Dialog::Close; // 되지 않음. 왜냐면 this파라미터 있어서

	//멤버 함수 포인터를 만드는 법
	void(Dialog::*f3)() = &Dialog::Close; //ok 외워두세요!

	//f3(); //이건 안됨 this가 없다

	Dialog dlg;
	//dlg.f3();//ok 결국 dlg.Close() 즉 f3(&dlg)
	//그런데 이 경우 컴파일러는 f3이라는 멤버를
	//찾게된다. 그래서 error
	(dlg.*f3)(); //f3는 함수포인터이므로 *f3하면 함수가 된다.!
	//.*연산자 우선순위를 함수호출() 보다 높여야

	Dialog* pDlg = &dlg;

	(pDlg->*f3)();
}