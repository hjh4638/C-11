#include <iostream>
using namespace std;

// �޸� �Ҵ� ���� ��å�� ���� ��å Ŭ����
template<typename T> class xallocator
{
public:
	// �޸� �Ҵ�� ������
	T* alloc(int sz){ return (T*) operator new(sizeof(T)*sz); }
	void deallocate(T* p){ operator delete(p); }

	// ������ �Ҹ��� ȣ���� ������
	void construct(T* p){ new(p)T; }
	void destruct(T* p){ p->~T(); }
};
template<typename T, typename Alloc = xallocator<T>> class Vector :
{
	Alloc alloc; // ���������� ��� �Ǵ� �������� ����ص� �˴ϴ�.
public:
	void resize(int sz)
	{
		// �޸𸮰� �����ؼ� �޸� �Ҵ��� �ؾ� �մϴ�.
		// malloc ? new ? poll ? system call ?
		T* p = alloc.allocate(sz);

		//�޸� ����
		alloc.deallocate(p);
	}
};

int main()
{
	Vector<int, xallocator<int>> v;

}