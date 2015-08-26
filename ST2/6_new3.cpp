#include <iostream>
using namespace std;

// new1���� Point �����ؿ�����

class Point{
	int x, y;
public:
	Point(){ cout << "������" << endl; }
	~Point(){ cout << "�Ҹ���" << endl; }
};

//�Ʒ� �Լ��� ��ƽ��ϴ�. - �� ������ ������
void* operator new(size_t sz, Point* p){
	return p;
}

//�̹� C++ ǥ�ؿ� �Ʒ� �Լ��� �����˴ϴ�. - 1994�⿡ ���� ����
// "Placement new"��� �Ҹ��� �Լ��Դϴ�.
// �̹� �����ϴ� �޸𸮿� �����ڸ� �ٽ� ȣ���ϴ� �����Դϴ�.
//void* operator new(size_t sz, void* p){
//	return p;
//}
int main(){
	Point p;

	//new Point; // ���ڰ� �Ѱ��� operator new() ȣ��
	new(&p) Point; //���� ���� ���� 2���� operator new(ȣ��)
				   //��ü p�� ���ؼ� �����ڸ� ��������� ȣ���� ��

	//p.Point();  // �������� ����� ȣ�� ? error.
	p.~Point(); // �Ҹ����� ����� ȣ�� ? ok..
}