#include <iostream>
using namespace std;

//1. new�� ��Ȯ�� ���� ���
//	 (A) operator new() �Լ��� ����ؼ� �޸� �Ҵ�
//	 (B) (A)�� �����ϰ� ��ü��� ������ ȣ��
//	 (C) �޸� �ּҸ� �ش� Ÿ������ ĳ�����ؼ� ����.

//2. new �� operator new()�� �ٸ� ����̴�.!!

class Point{
	int x, y;
public:
	Point(){ cout << "������" << endl; }
	~Point(){ cout << "�Ҹ���" << endl; }
};

int main(){

	//������ ȣ����� �޸� �Ҵ縸 �ϴ� ���
	Point* p = static_cast<Point*>(operator new(sizeof(Point)));
	operator delete(p);

	//Point* p = new Point;
	//delete p;

}