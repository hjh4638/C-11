#include <iostream>
using namespace std;

int a;
int* p;
int x[10]; //int[10] �� x�� Ÿ���̴�
		   //T[N]
//traits ����� �� �ٽ� ����

// primary template : false_type�� �⺻ Ŭ������
// �κ� ����ȭ ���� : true_type�� �⺻ Ŭ������
template<typename T> struct IsArray : false_type{
	static const int size = -1; // �迭�� �ƴϹǷ�
};
template<typename T, int N> struct IsArray<T[N]> : true_type{
	static const int size = N;
};
template<typename T> void foo(const T& a)
{
	if (IsArray<T>::value)
	{
		cout << "�迭, ũ���" << IsArray<T>::size<< endl;
	}
	else
	{
		cout << "�迭 �ƴ�" << endl;
	}
}

int main()
{
	int x[10];
	foo(x);
}