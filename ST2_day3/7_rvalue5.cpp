#include <iostream>
using namespace std;

// �Լ� �����ε��� ����
void foo(int&){ cout << "int&" << endl; }				//1
void foo(int&&){ cout << "int&&" << endl; }				//2
void foo(const int&){ cout << "const int&" << endl; }	//3

int main()
{
	int n = 10;

	foo(n);	// 1�� ���ٸ� 3��
	foo(10);// 2�� ���ٸ� 3��

	int&& r = 10;
	foo(r); // 1 ? 2	"rvalue reference�� lvalue �̴�."
			
			// rvalue��� ����
			// rvalue reference�� ȥ������ ������
}