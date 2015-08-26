#include <iostream>
using namespace std;

//	B. ���� ��� - ����Ʈ ������ ���� �� ���� �θ� ���Ǵ� ���

template<typename T> class Ptr
{
	T* obj;
	int* ref;
public:
	Ptr(T* p = 0) :obj(p){
		ref = new int(1);
	}

	//���� ��� ����� ���� ������
	Ptr(const Ptr& p)
	{
		//���� ���� �Ŀ�
		obj = p.obj;
		ref = p.ref;

		//ã����� ����
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