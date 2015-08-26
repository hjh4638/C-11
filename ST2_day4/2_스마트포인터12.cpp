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
	T* operator->(){ return obj; }
	T& operator*(){ return *obj; }
};

// 참조계수를 조작하는 함수는 반드시 상수 함수 이어야 한다.
template<typename T> class LightRefBase
{
	mutable int mCount;
public:
	inline LightRefBase() :mCount(0){}
	inline ~LightRefBase(){}
	inline void incStrong() const { ++mCount; }
	inline void decStrong() const // decStrong( const RefBase* this )
	{
		// this : const RefBase* 입니다.
		// static cast는 상수성을 제거할 수 없습니다.
		// RefBase*			=> T*		: ok!!
		// const RefBase*	=> const T* : ok!!
		// const RefBase*	=> T*		: error
		if (--mCount == 0)
			delete static_cast<const T*>(this);
	}
};

class Truck : public LightRefBase<Truck>
{
public:
	~Truck(){ cout << "Truck" << endl; }
};

int main()
{
	sp<Truck> p = new Truck;
	//const Truck t;
	//t.incStrong(); // 상수 객체도 참조계수 관리는 할 수
				// 있어야 한다.
}

class Test
{
	int x;
public:
	void foo() // void foo( Test* const this) const Test* this
	{
		// this 잦체는 const이지만 this가 가르키는 곳은 const 아님
		this->x = 10;
	}
	void goo() const // void goo(const Test* const this)
	{
		//this도 const, this가 가리키는 곳도 const
		this->x = 10; // error
	}
};