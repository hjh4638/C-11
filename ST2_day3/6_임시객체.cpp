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

int main()
{
	cout << "AAA" << endl;
	//Point p;
	
	Point(); // Ŭ�����̸�()

	cout << "BBB" << endl;
}