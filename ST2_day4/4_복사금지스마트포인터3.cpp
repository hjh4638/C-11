#include <iostream>
using namespace std;

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
	inline void operator()(void* p) const
	{
		cout << "delete 사용 " << endl;
		delete p;
	}
};

// 배역 delete를위한 부분 전문화 버전
template<typename T> struct DefaultDelete < T[] >
{
	inline void operator()(void* p) const
	{
		cout << "배열delete 사용 " << endl;
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
		D()(obj);
	}
	inline T* operator->()		{ return obj; }
	inline T& operator*()		{ return *obj; }
};

int main()
{
	UniquePtr<int> p1(new int);
	UniquePtr<int[]> p2(new int[10]); // 이코드는
									// 위의 UniquePtr에서 int[]* obj; 코드로 생성됩니다.
									// int[]*는 잘못된 표현입니다. 그래서 error
}
