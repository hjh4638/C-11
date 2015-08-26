#include <iostream>
using namespace std;


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

// �θ� �������� ���·� delete �ϸ� �θ��� �Ҹ��ڸ� ȣ��˴ϴ�.
// �ڽ� �Ҹ��ڸ� ȣ��ǰ� �Ϸ��� �Ҹ��� ��ü�� �����Լ� �̾�� �մϴ�.

//��� : ��� �θ��� �Ҹ��ڴ� �����Լ� �̾�� �Ѵ�.
/*
class RefBase
{
	int mCount;
public:
	RefBase() :mCount(0){}
	virtual ~RefBase(){}
	void incStrong(){ ++mCount; }
	void decStrong(){ if (--mCount == 0)delete this; }
};
*/

// core/include/utils/RefBase.h ���� ��� LightRefBase ã�ƺ�����.
template<typename T> class LightRefBase
{
	int mCount;
public:
	inline LightRefBase() :mCount(0){}
	inline ~LightRefBase(){}
	inline void incStrong(){ ++mCount; }
	inline void decStrong()
	{
		if (--mCount == 0)
			delete static_cast<T*>(this); 
	}
};

class Truck : public LightRefBase<Truck>
{
public:
	~Truck(){ cout << "Truck" << endl; }
};

int main()
{
	sp<Truck> p = new Truck; // �ɱ�� ?
}