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

// ��ü �ȿ� ���� ����� �ڵ����� �������ִ� ����Ʈ ������
template<typename T> class sp
{
	T* obj;
	int* ref;
public:
	explicit sp(T* p = 0)			:obj(p)			
	{
		if(obj) obj->incStrong();
	}
	sp(const sp& p)			:obj(p.obj)		
	{
		if (obj) obj->incStrong();
	}
	~sp()
	{
		if (obj) obj->decString();
	}

	// ����Ʈ�������� �⺻ ->�� *
	T* operator->(){ return obj; }
	T& operator*(){ return *obj; }


};

int main()
{
	Car* p1 = new Car;
	Car* p2 = p1;
}