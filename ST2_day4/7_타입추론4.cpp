#include <iostream>
using namespace std;

// ��Ģ 3. Universal reference �� ���
// int&& : rvalue reference - rvalue �� ���� �� �ִ�.
// T&& : universal reference ( forward reference ��� �մϴ�.)

// ���ڷ� ���޵Ǵ� ǥ���� lvalue �̸� T&&�� lvalue reference �� �ǰ�
// ���ڷ� ���޵Ǵ� ǥ���� rvalue �̸� T&&�� rvalue reference �� �ȴ�.
template<typename T> void foo(T&& a)
{

}

int main()
{
	int n = 10;
	foo(n);
	foo(10);

	int& r = n;
	foo(r);
}