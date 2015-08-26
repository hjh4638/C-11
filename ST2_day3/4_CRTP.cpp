#include <iostream>
using namespace std;

// CRTP : Curiously Recurring Template Pattern
//		  부모가 템플릿인데..
//		  자식 만들 때 자신의 이름을 부모에게 인자로 전달해주는 기술
//		  미래에 만들어질 자식의 이름을 사용할 수 있다.

// CRTP를 사용해서 비 가상함수를 가상함수 처럼 동작하게 하는 예제

// MS의 라이브러리중 ATL, WTL 이라는 라이브러리가 이 기술을 사용!
template<typename T> class Window
{
public:
	void msgLoop() // msgLoop(this)
	{
		(static_cast<T*>(this)->onClick(); // 1
	}
	void onClick(){ cout << "Window onClick" << endl; } // 1
};
class MyWindow : public Window<MyWindow>
{
public:
	void onClick(){ cout << "MyWindow onClick" << endl; } // 2
};

int main()
{
	MyWindow w;
	w.msgLoop(); // 1 ? 2 예측해 보세요..
}