#include <iostream>
using namespace std;

// args : �������� ���ڸ� ��Ÿ����. "Parameter Pack"
int n = 0;

// �ᱹ �Ʒ� ���ø��� foo() �Լ��� 4�� �����˴ϴ�.
// ���� ���� �������� 1��° ���ڴ� �̸��� �ִ� ������ �޾ƾ� �Ѵ�.
template<typename T, typename ... Types> void foo(T value, Types ... args)
{
	//static int n = 0;
	++n;
	cout << n << " ";

	cout << typeid(T).name() << " : " << value << endl;
	
	foo(args...); // args : 3.3, 'a', "hello"
}

void foo(){}

int main()
{
	foo(1, 3.3, 'a', "hello"); // value : 1	args : 3.3, 'a', "hello"
}