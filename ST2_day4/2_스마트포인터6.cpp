#include <iostream>
using namespace std;

//��������� ��ü�ȿ� ���Խ�Ű��..
class Car
{
	// Car�� ���������...
	int mCount; // ���� ���
public:
	Car() :mCount(0){}
	~Car(){ cout << "~Car" << endl; }

	void incStrong(){ ++mCount; }
	void decStrong(){ if (--mCount == 0)delete this; }
};
int main()
{
	Car* p1 = new Car;
	p1->incStrong(); // ��Ģ 1. ��ü ������ ���� ��� ����

	Car* p2 = p1;
	p2->incStrong(); // ��Ģ 2. ��ü �ı��� ���� ��� ����

	p2->decStrong();
	p1->decStrong(); // ��Ģ 3. ��ü ��� �� ������� ����
}