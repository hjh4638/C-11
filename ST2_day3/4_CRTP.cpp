#include <iostream>
using namespace std;

// CRTP : Curiously Recurring Template Pattern
//		  �θ� ���ø��ε�..
//		  �ڽ� ���� �� �ڽ��� �̸��� �θ𿡰� ���ڷ� �������ִ� ���
//		  �̷��� ������� �ڽ��� �̸��� ����� �� �ִ�.

// CRTP�� ����ؼ� �� �����Լ��� �����Լ� ó�� �����ϰ� �ϴ� ����

// MS�� ���̺귯���� ATL, WTL �̶�� ���̺귯���� �� ����� ���!
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
	w.msgLoop(); // 1 ? 2 ������ ������..
}