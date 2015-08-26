// 9_nullptr - C++11�� ���ο� ����

#include <iostream>
using namespace std;

void foo(int n)		{ cout << "int" << endl; }  // 1
void foo(void* p)	{ cout << "void*" << endl; } // 2
void goo(char* p)	{ cout << "char*" << endl; } // 2

//// C/C++ ���� ������ ������ NULL�� �Ʒ� ó�� ������� �ֽ��ϴ�.
//#ifdef __cplusplus
//	#define NULL 0
//#else
//	#define NULL (void*)0
//#endif

int main()
{
	goo(NULL);
	foo(NULL); // int
}