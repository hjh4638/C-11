#include <iostream>
using namespace std;

template<typename T> class Stack
{
	T buff[100];
	int index;

public:
	Stack() : index(-1){}

	// T�� ũ�Ⱑ ū ��ü�� ���� �ֵ�.
	// call by value �� ���� ��ü�� �޸𸮿� �ѹ� �� �����Ѵ�.
	// const T& �� ����.
	// void push(T a){buff[++index] = a;}

	void push(const T& a){ buff[++index] = a; };

	// pop()�� ���ſ� ������ ���ÿ� �ϸ� ����ȭ �� �� ����.
	// �ӽð�ü�� ���� �� ����.
	//T  pop()		{ return buff[index--]; }

	void pop(){ --index; }			  // ���Ÿ�
	T&	 top(){ return buff[index]; } // ���ϸ�
};

// C++���� template ����� �����̳� (list, stack, vector��)��
// ��� �Լ��� ���ſ� ������ ���ÿ� ���� �ʴ´�.

// 1. ���������� ���� �ӽð�ü�� �����ϱ� ����
// 2. ���� �������� ���º����� ����

int main()
{
	Stack<int> s;
	s.push(10);
	s.push(20);
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
}