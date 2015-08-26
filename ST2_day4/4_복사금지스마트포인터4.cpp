#include <iostream>
using namespace std;

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
	inline void operator()(void* p) const
	{
		cout << "delete ��� " << endl;
		delete p;
	}
};

// �迪 delete������ �κ� ����ȭ ����
template<typename T> struct DefaultDelete < T[] >
{
	inline void operator()(void* p) const
	{
		cout << "�迭delete ��� " << endl;
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

// �迭�϶��� ���� �κ� ����ȯ - �κ� ����ȭ ����������
// ����Ʈ ���ڸ� ǥ������ �ʰ� �˴ϴ�.
template<typename T, typename D>
class UniquePtr<T[], D>
{
	T* obj;

	UniquePtr(const UniquePtr&) = delete;
	UniquePtr& operator=(const UniquePtr& p) = delete;
public:
	inline explicit UniquePtr(T* p = 0) :obj(p){}
	inline ~UniquePtr(){ D()(obj); }

	// �迭 ���������� [] �����ڵ� �����ϸ� �����ϴ�.
	inline T& operator[](int index){ return obj[index]; }
	
	// �Ʒ� 2���� �־ ������, C++ ǥ�ؿ����� �迭����������
	// �Ʒ� 2���� �����߽��ϴ�.
//	inline T* operator->()		{ return obj; }
//	inline T& operator*()		{ return *obj; }
};


// core/include/utils/UniquePtr.h
int main()
{
	UniquePtr<int> p1(new int);
	UniquePtr<int[]> p2(new int[10]); // ���ڵ��
	

	//
	p2[0] = 10; // 1 ok
	//p1[1] = 20; // 2 error
	//*p2 = 10; // 3 error
	*p1 = 10; // 4 ok..

	UniquePtr<int, Freer> p3((int*)malloc(100));
}
