#include <iostream>
#include <type_traits>
using namespace std;

//trivial constructor(�ڸ��� ������) : �ƹ� �ϵ� ���� �ʴ� ������

//1. �����Լ��� ����
//2. �θ� ���ų� �θ��� �����ڰ� trivial �ϰ�
//3. ��ü�� ����� ���ų� ��ü�� ����� �����ڰ� trivial �ϰ�
//4. ����ڰ� ���� �����ڰ� ���ٸ�

//�����ڴ� "trivial" �ϴ�!!

class Base{};

class A //: public Base
{
	//Base b;
public:
	//virtual void foo(){}
};

int main()
{
	//A�� �����ڴ� trivial �ұ�� ??
	A* p = (A*)malloc(sizeof(A));//�����ڰ� ȣ����� �ʴ´�.

	new(p) A;//p �޸𸮿� ���� ������ ȣ��
			 // "placement new"s
	p->foo();
}