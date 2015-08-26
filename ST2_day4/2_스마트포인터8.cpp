#include <iostream>
using namespace std;

class RefBase
{
	int mCount; 
public:
	RefBase() :mCount(0){}
	virtual ~RefBase(){}
	void incStrong(){ ++mCount; }
	void decStrong(){ if (--mCount == 0)delete this; }
};

template<typename T> class sp
{
	T* obj;
public:
	sp(T* p = 0) :obj(p)
	{
		if (obj) obj->incStrong();
	}
	sp(const sp& p) :obj(p.obj)
	{
		if (obj) obj->incStrong();
	}
	~sp()
	{
		if (obj) obj->decStrong();
	}

	// ����Ʈ�������� �⺻ ->�� *
	T* operator->(){ return obj; }
	T& operator*(){ return *obj; }


};

// sp�� ����Ϸ��� �ݵ�� incStrong()�� decStrong()�� �־�� �Ѵ�.
// sp�� ����Ϸ��� _RefBase_�� �Ļ�Ŭ������ ������ �Ѵ�.
class Truck : public RefBase
{
public:
	~Truck(){ cout << "Truck" << endl; }
};

int main()
{
	sp<Truck> p = new Truck; // �ɱ�� ?
}