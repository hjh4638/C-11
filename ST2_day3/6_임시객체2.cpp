#include <iostream>
using namespace std;

// Point p; => �̸� �ִ� ��ü p, ���� ����� ���� ����
// Point() => �̸� ���� �ӽð�ü ����. ���� ���忡���� ��ȿ..


class Point
{
	int x, y;
public:
	Point(){ cout << "������" << endl; }
	~Point(){ cout << "�Ҹ���" << endl; }

	Point(const Point&){ cout << "���������" << endl; }
};

// �Լ� ���ڿ� �ӽð�ü
void foo(Point p){}

int main()
{
	Point p;
	foo(p);

	// ��Ÿ���� �Լ� ���ڷ� �����ϱ� ���� ��ü��� �ӽð�ü�� ����.
	foo(Point());
}