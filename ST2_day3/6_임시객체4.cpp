#include <iostream>
using namespace std;

struct Point
{
	int x, y;
};

Point p = { 1, 1 };

//Point foo() : ������ - �ӽð�ü ����, lvalue�� �� �� ����.
Point& foo() // �������� - �ӽð�ü �����ȵ�. lvalue�� �� �� �ִ�.
{				//		��, ���������� ������ ���� �ȵȴ�!!!
	return p;
}

int main()
{
	// �ӽð�ü�� lvalue �� �� �� �����ϴ�.
	// �Ʒ� �ڵ尡 VC++������ ������ ������ g++ ������ ������ ����
	foo().x = 10;	// �ӽð�ü.x = 10
	cout << p.x << endl; // 1
}