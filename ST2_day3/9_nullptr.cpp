// 9_nullptr - C++11�� ���ο� ����

#include <iostream>
using namespace std;

void foo(int n)		{ cout << "int" << endl; }  // 1
void foo(void* p)	{ cout << "void*" << endl; } // 2
void goo(char* p)	{ cout << "char*" << endl; } // 2

int main()
{
	foo(0);					// 1��� - 0�� �����̴�
	foo((void*)0);			// 2��� - 0�� �����̴�

#define NULL (void*)0
	foo(NULL);

	goo(NULL);			// C ok.. void* => �ٸ� ������ �Ͻ��� ��ȯ ���
						// C++ error.


	//int* p1 = 0; // 0�� ���� ������ �����ͷ� �Ͻ��� ����ȯ �ȴ�.
	//int* p2 = 10;// error. 10�� �����ͷ� ����ȯ �ȵ�.
}