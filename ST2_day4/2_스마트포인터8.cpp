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

	// 스마트포인터의 기본 ->와 *
	T* operator->(){ return obj; }
	T& operator*(){ return *obj; }


};

// sp를 사용하려면 반드시 incStrong()와 decStrong()가 있어야 한다.
// sp를 사용하려면 _RefBase_의 파생클래스로 만들어야 한다.
class Truck : public RefBase
{
public:
	~Truck(){ cout << "Truck" << endl; }
};

int main()
{
	sp<Truck> p = new Truck; // 될까요 ?
}