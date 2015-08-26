#include <iostream>
using namespace std;

template<typename ... Types>
void goo(Types ... args)
{
	cout << "goo" << endl;
}

void hoo(int a, double d, char c)
{
	cout << "hoo" << endl;
}

void joo(int* a, double* b, char* c){ cout << "joo" << endl; }

// Types : �������� Ÿ���� ������ �ִ� Ÿ���� ����
// args : �������� ���� ������ �ִ� ���� ���� - "Parameter Pack"
template<typename ... Types>
void foo(Types ... args)
{
	// Parameter Pack �ȿ� ������ �˰� �ʹٸ�
	cout << sizeof...(args) << endl;
	cout << sizeof...(Types) << endl;

	// Parameter Pack �� �ٸ� �Լ��� �����ϴ� ���
	goo(args...);
	hoo(args...);
	joo(&args...);
}

int main()
{
	foo(1, 3.3, 'a');
}