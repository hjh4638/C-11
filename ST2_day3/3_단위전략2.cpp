#include <iostream>
using namespace std;

// 메모리 할당 해지 정책을 담은 정책 클래스
template<typename T> class xallocator
{
public:
	// 메모리 할당과 해지만
	T* alloc(int sz){ return (T*) operator new(sizeof(T)*sz); }
	void deallocate(T* p){ operator delete(p); }

	// 생성자 소멸자 호출을 별도로
	void construct(T* p){ new(p)T; }
	void destruct(T* p){ p->~T(); }
};
template<typename T, typename Alloc = xallocator<T>> class Vector :
{
	Alloc alloc; // 단위전략은 상속 또는 포함으로 사용해도 됩니다.
public:
	void resize(int sz)
	{
		// 메모리가 부족해서 메모리 할당을 해야 합니다.
		// malloc ? new ? poll ? system call ?
		T* p = alloc.allocate(sz);

		//메모리 해지
		alloc.deallocate(p);
	}
};

int main()
{
	Vector<int, xallocator<int>> v;

}