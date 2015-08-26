#include <iostream>
using namespace std;

class Car
{
public:
	void Go()	{ cout << "Car Go" << endl; }
	~Car()		{ cout << "~Car" << endl; }
};

// ���� : ������ ��ü�� �ٸ� Ÿ���� ������ ó�� ���Ǵ� ��

// ���� : * �����ڿ� -> �����ڸ� ������ �ؼ� ������ ó�� ���̰��Ѵ�.

//		���� !! *�����ڴ� ���� ������ �ؾ� �մϴ�.

// ���� : ��¥ �����Ͱ� �ƴ϶� ��ü�̴�.
//		  ����/����/����/�Ҹ��� ��� ������ ����ڰ� ������ �� �ִ�.
//		  ��ǥ�� Ȱ���� �Ҹ��ڿ����� �ڵ� ���� ���
//		  (garbage collector�� ������ ���)

// �Ʒ� Ŭ������ �ٽ��Դϴ�.
class Ptr
{
	Car* obj;
public:
	Ptr(Car* p = 0) :obj(p){}

	~Ptr(){ delete obj; }
	Car* operator->(){ return obj; }
	
	// ���� �ݵ�� ���� �����ؾ� �մϴ�.
	// Car ������ �ӽð�ü �Դϴ�. - �ٸ� �ڵ����� ����� ���ϴ�.!
	Car& operator*(){ return *obj; }
};

int main()
{
	//�Ʒ� 2���� �� ������ ������.
	Ptr p = new Car;		// Ptr p(new Car)�� ������ ������.
	p->Go();				// ( p.operator->()) Go() �� ���������
							// ( p.operator->())->Go() �� �ؼ��� �ݴϴ�.

	(*p).Go(); // ��¥ ������ ó�� ���̷��� *�� �Ǿ�� �Ѵ�.
}