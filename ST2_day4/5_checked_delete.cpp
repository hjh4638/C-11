#include <iostream>
using namespace std;
class Test; // Ŭ���� ���漱�� - ������ ������ ���
			//					������ ������ ����� �� �ִ�.

Test* p; // incomplete object(�ҿ����� ��ü)
		 // ���漱�� �ִ� Ÿ���� ������
		 // delete �ϸ� �Ҹ��ڸ� ȣ������ ���Ѵ�.

// checked delete - boost���� ���ʷ� ���� ����.
void foo(Test* pt)
{
	enum{ type_must_be_complete = sizeof(Test) }; // �ҿ��� ��ü�� ũ�⸦ ���� �� ����.
	delete pt;
}

class Test
{
public:
	Test(){ cout << "������" << endl; }
	~Test(){ cout << "�Ҹ���" << endl; }
};

int main()
{
	Test* p = new Test;
	foo(p);
}