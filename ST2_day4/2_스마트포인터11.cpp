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

	// 스마트포인터의 기본 ->와 *
	T* operator->(){ return obj; }
	T& operator*(){ return *obj; }


};

// 부모 포인터인 상태로 delete 하면 부모의 소멸자만 호출됩니다.
// 자식 소멸자를 호출되게 하려면 소멸자 자체가 가상함수 이어야 합니다.

//결론 : 모든 부모의 소멸자는 가상함수 이어야 한다.
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

// core/include/utils/RefBase.h 파일 열어서 LightRefBase 찾아보세요.
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
	sp<Truck> p = new Truck; // 될까요 ?
}