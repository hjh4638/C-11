#include <iostream>
using namespace std;

class Point{
	int x, y;
public:
	Point(int a, int b){}
};

int main(){
	// 1. ���� Point �Ѱ��� ����� ������..
	Point* a1 = new Point(1, 2);
	// 2. ���� Point 10���� ����� ������..
	//Point* p2 = new Point[10]; // �����!!

	//�ذ�å : �޸� �Ҵ�� ������ ȣ���� �и��ϸ� ���� ����.
	Point* p3 = static_cast<Point*>(operator new(sizeof(Point) * 10));

	//�Ҵ�� �޸��� �����ڸ� ȣ���ؼ� ��ü�� �ʱ�ȭ �Ѵ�.
	for (int i = 0; i < 10; i++){
		new(&p3[i]) Point(0, 0);
	}

	//�̰�� �Ҹ��� ȣ�� �� �޸� ������ �Ʒ�ó�� �ؾ��Ѵ�.
	for (int i = 9; i >= 0; i--){
		p3[i].~Point();
	}
	operator delete(p3);

	// Point�� ���ÿ� 10�� ����� ������
	char buf[sizeof(Point) * 10];
	Point* p4 = reinterpret_cast<Point*>(&buf);

	//p4�� ���� �����ڸ� ��������� ȣ���ϰ� ����ϸ� �ȴ�.
	//����� �Ҹ��ڵ� ��������� ȣ���ؾ� �Ѵ�.
}