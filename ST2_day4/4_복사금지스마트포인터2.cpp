#include <iostream>
using namespace std;

// 메모리 해지 전략을 담은 함수 객체들
struct Freer
{
	inline void operator()(void* p) const
	{
		cout << "free 사용 " << endl;
		free(p);
	}
};

template<typename T> struct DefaultDelete
{
	// 주의 void*를 delete 하면 소멸자가 호출되지 않습니다.
	// inline void operator()(void* p) const
	inline void operator()(void* p) const
	{
		cout << "delete 사용 " << endl;
		delete p;
	}
};
// Unique Ptr
template<typename T, typename D = DefaultDelete<T>> class UniquePtr
{
	T* obj;

	UniquePtr(const UniquePtr&) = delete;
	UniquePtr& operator=(const UniquePtr& p) = delete;
public:
	inline explicit UniquePtr(T* p = 0) :obj(p){}
	inline ~UniquePtr(){
		//D d; // 함수객체 생성
		//d(obj); // 함수객체 이므로 함수 처럼 사용
		D()(obj);
	}
	inline T* operator->()		{ return obj; }
	inline T& operator*()		{ return *obj; }
};

int main()
{
	UniquePtr<int, DefaultDelete<int>>	p1(new int);
	UniquePtr<int, Freer>				p2( (int*)malloc(100) );

	UniquePtr<int> p3(new int);
}
