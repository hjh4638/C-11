#include <iostream>
using namespace std;

class Animal{};
class Dog :public Animal{  };


template<typename T> class Ptr
{
	T* obj;
	int* ref;
public:
	explicit Ptr(T* p = 0) :obj(p){
		ref = new int(1);
	}

	Ptr(const Ptr& p)
	{
		obj = p.obj;
		ref = p.ref;

		++(*ref);
	}
	
	//2일차 2교시 참고
	template<typename U > Ptr(const Ptr<U>& p)
	{
		obj = p.obj;
		ref = p.ref;
		++(*ref);
	}
	template<typename> friend class Ptr;

	// 그외 대입연산자(=), ==, != 연산자가 template 버전으로 있어야
	// 한다.

	~Ptr(){
		--(*ref);
		if (*ref == 0){
			delete obj;
			delete ref;
		}
	}
	T* operator->()		{ return obj; }
	T& operator*()		{ return *obj; }
};

int main()
{
	Ptr<Dog> p1(new Dog);
	Ptr<Animal> p2 = p1; // 다형성 : 부모 포인터로 자식을 
						// 가르킬 수 있어야한다.
}