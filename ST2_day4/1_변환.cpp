// 1_��ȯ
#include <iostream>
using namespace std;

// ��ȯ ������ : ��ü(Point) => �ٸ� Ÿ��(int)
// ��ȯ ������ : �ٸ� Ÿ��(int) => ��ü(Point)
class Point
{
	int x, y;
public:
	Point()					:x(0), y(0){}
	Point(int a, int b)		:x(a), y(b){}

	// ��ȯ ������ : ���ڰ� �Ѱ��� ������
	//				�ٸ� Ÿ���� ��ü�� �Ͻ��� ����ȯ�ǰ� �Ѵ�.
	Point(int a) :x(a), y(0){}

	//��ȯ ������ �Լ� : ��ü�� �ٸ� Ÿ������ �Ͻ��� ����ȯ
	//					�ǵ��� �Ѵ�.
	//Ư¡ : �Լ� �̸��� ����Ÿ���� ��� �����Ƿ� ���� Ÿ����
	//		ǥ������ �ʴ´�.
	operator int(){ return x; }
};

int main()
{
	Point p1;
	Point p2(1, 2);

	int n = 10;

	n = p2; // Point => int ��ȯ : p2.operator int()�� �ʿ�
	p2 = n; // int => Point ��ȯ : n.operator Point()�� �ʿ�
			//				�׷��� n�� ����� Ÿ���� �ƴϴ�!
}

/*
int main()
{
	double d = 3.4;
	int n = d; // �⺻ Ÿ���� ���� �Ͻ��� ����ȯ�� �����ϴ�

	Point p(1, 2);
	n = p; // p.operator int() �Լ��� ������ȴ�.!
}
*/