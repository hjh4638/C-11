#include <iostream>
using namespace std;

void foo(int n) { cout << "int" << endl; }
void foo(void* p){ cout << "void*" << endl; }
void goo(char* p){ cout << "char*" << endl; }

int main()
{
	int* p = nullptr;
	char* p2 = nullptr;

	//int n = nullptr; // error.. 포인터 0이지 정수 0이 아니다!!

	foo(nullptr);
	goo(nullptr);
}