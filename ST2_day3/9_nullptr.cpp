// 9_nullptr - C++11의 새로운 개념

#include <iostream>
using namespace std;

void foo(int n)		{ cout << "int" << endl; }  // 1
void foo(void* p)	{ cout << "void*" << endl; } // 2
void goo(char* p)	{ cout << "char*" << endl; } // 2

int main()
{
	foo(0);					// 1사용 - 0은 정수이다
	foo((void*)0);			// 2사용 - 0은 정수이다

#define NULL (void*)0
	foo(NULL);

	goo(NULL);			// C ok.. void* => 다른 포인터 암시적 변환 허용
						// C++ error.


	//int* p1 = 0; // 0은 정수 이지만 포인터로 암시적 형변환 된다.
	//int* p2 = 10;// error. 10은 포인터로 형변환 안됨.
}