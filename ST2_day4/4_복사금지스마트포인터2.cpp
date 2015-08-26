#include <iostream>
using namespace std;

// �޸� ���� ������ ���� �Լ� ��ü��
struct Freer
{
	inline void operator()(void* p) const
	{
		cout << "free ��� " << endl;
		free(p);
	}
};

template<typename T> struct DefaultDelete
{
	// ���� void*�� delete �ϸ� �Ҹ��ڰ� ȣ����� �ʽ��ϴ�.
	// inline void operator()(void* p) const
	inline void operator()(void* p) const
	{
		cout << "delete ��� " << endl;
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
		//D d; // �Լ���ü ����
		//d(obj); // �Լ���ü �̹Ƿ� �Լ� ó�� ���
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
