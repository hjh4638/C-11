#include <iostream>
using namespace std;

void foo(int n) { cout << "int" << endl; }
void foo(void* p){ cout << "void*" << endl; }
void goo(char* p){ cout << "char*" << endl; }

int main()
{
	int* p = nullptr;
	char* p2 = nullptr;

	//int n = nullptr; // error.. ������ 0���� ���� 0�� �ƴϴ�!!

	foo(nullptr);
	goo(nullptr);
}