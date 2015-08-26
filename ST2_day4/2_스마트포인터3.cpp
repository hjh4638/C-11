#include <iostream>
using namespace std;

//	B. 참조 계수 - 스마트 포인터 만들 때 가장 널리 사용되는 방식

template<typename T> class Ptr
{
	T* obj;
	int* ref;
public:
	Ptr(T* p = 0) :obj(p){
		ref = new int(1);
	}

	//참조 계수 방식의 복사 생성자
	Ptr(const Ptr& p)
	{
		//얕은 복사 후에
		obj = p.obj;
		ref = p.ref;

		//찾조계수 증가
		++(*ref);
	}
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
	Ptr<int> p1 = new int;
	Ptr<int> p2 = p1;

}