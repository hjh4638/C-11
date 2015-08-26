#include <iostream>
using namespace std;

// 1. template 으로 만들어야 한다.

// 2. 얕은 복사 문제를 해결해야 한다.

//	A. 깊은 복사 - 스마트 포인터 만들때는 거의 사용하지 않는다.
//	B. 참조 계수 - 스마트 포인터 만들 때 가장 널리 사용되는 방식
//	C. 소유권이전 - ??
//	D. 복사 금지 - 요즘에 뜨고 있는 방식.
template<typename T> class Ptr
{
	T* obj;
public:
	Ptr(T* p = 0) :obj(p){}
	~Ptr(){ delete obj; }
	T* operator->()		{ return obj; }
	T& operator*()		{ return *obj; }
};

int main()
{
	Ptr<int> p1 = new int;
	Ptr<int> p2 = p1;


}