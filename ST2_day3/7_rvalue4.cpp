#include <iostream>
using namespace std;

struct Point
{
	int x, y;
};

Point p;
Point foo(){ return p; }

int main()
{
	int n = 10;

	// &		: lvalue �� ����Ų��
	// const &  : lvalue �� rvalue�� ��� ����Ų��.
	// &&		: rvalue �� ����Ų��
	const int& r1 = n;
	const int& r2 = 10;

	int&& r3 = 10; // ok !! rvalue ���� ����
	int&& r4 = n;  // error

	Point&& r5 = foo(); // ok... �ӽð�ü�� rvalue �̴�.
						// �� ���� �ӽð�ü�� ������ ����ȴ�.
						// r5�� ������ ���� ���������� ��� �ִ�.
	
	const Point& r6 = foo(); // �̼����� ������ ���������
							// ��� ��ü�� ���·θ� ����ؾ� �Ѵ�
	cout << r1 << endl << r2 << endl;
}