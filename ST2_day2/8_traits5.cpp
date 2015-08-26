#include <iostream>
using namespace std;

//0,1�� �Լ� �����ε��� �ǰ� �ϴ� ���

//��� int�� ����� Ÿ������ ����� �ý���
//Modern C++�� ������ Andrei Alexandr.. �� 2000�⵵�� ������

//������ �ð� ������ ��� ����� �Լ� �����ε��� Ȱ��� �� �ִ�.
template<int N> struct int2type
{
	enum{ value = N };
};
template<typename T> struct IsPointer
{
	enum{ value = false };
};
template<typename T> struct IsPointer<T*>
{
	enum{ value = true };
};

//�������� ��츦 ó���ϴ� �Լ�
template<typename T> void printv_imp(T a, int2type<1>)
{
	cout << a << ", " << a << endl;
}
//�����Ͱ� �ƴ� ���
template<typename T> void printv_imp(T a,int2type<0>)
{
	cout << a << endl;
}

//����ڰ� ����ϴ� ����
template<typename T> void printv(T a)
{
	printv_imp(a, int2type<IsPointer<T>::value>());
}

int main(){
	int n = 3;
	printv(&n);
}
//int main
//{
//	foo(0);
//	foo(1);
//	int2type<0> t0;
//	int2type<1> t1;
//	foo(t0);
//	foo(t1); //t0�� t1�� �ٸ� Ÿ�Դϴ�.
//			 //foo(t0), foo(t1)�� �ٸ� �Լ� ȣ��
//}

