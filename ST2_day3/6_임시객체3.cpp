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
// ��Ÿ������ �����ϴ� �Լ��� �ӽð�ü�� ����� �ȴ�.!
void foo(Point p){}

Point foo()
{
	// Point p2;
	cout << "foo" << endl;

	// ���Ͽ뵵�θ� ��ü�� ����ٸ�.. �Ʒ�ó�� �ϴ� ���� ����.
	return Point(); //�ӽð�ü�� ����鼭 ����!!
					// Return Value Optimization( RVO ) ��� �Ҹ��� ���
					// C++ IDioms

					// ���� C++ �����Ϸ� : NRVO�� ���� �Ѵ�.
					// Named RVO
}
int main()
{
	Point p1;
	cout << "AAA" << endl;
	p1 = foo();
	cout << "BBB" << endl;

	// ��Ÿ���� �Լ� ���ڷ� �����ϱ� ���� ��ü��� �ӽð�ü�� ����.
	//foo(Point());
}

// �������� ����.. ȭ�� ��� ��� ������ ������..
// 1. ������ - p1
// 2. AAA
// 3. ������ - p2
// 4. foo
// 5. ���� ������ - ���Ͽ� �ӽð�ü
// 6. �Ҹ��� - p2
// 7. �Ҹ��� - �ӽð�ü��
// 8. BBB
// 9. �Ҹ��� - p1