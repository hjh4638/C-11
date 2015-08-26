#include <iostream>
using namespace std;

// 함수 오버로딩과 참조
void foo(int&){ cout << "int&" << endl; }				//1
void foo(int&&){ cout << "int&&" << endl; }				//2
void foo(const int&){ cout << "const int&" << endl; }	//3

int main()
{
	int n = 10;

	foo(n);	// 1번 없다면 3번
	foo(10);// 2번 없다면 3번

	int&& r = 10;
	foo(r); // 1 ? 2	"rvalue reference는 lvalue 이다."
			
			// rvalue라는 용어와
			// rvalue reference를 혼동하지 마세요
}