#include <iostream>
using namespace std;

void foo(int n)		{ cout << "foo" << endl; }
void goo(char* p)	{ cout << "goo" << endl; }

void hoo(int a, int b){ cout << "hoo" << endl; }
void koo(){ cout << "koo" << endl; }
// 함수가 수행되는 시간을 확인하는 도구를 만들어 봅시다.
template<typename F, typename ... Types>
void HowLong(F f, Types ... args)
{
	// 시간 측정
	f(args...);
	// 시간 측정 후 출력
}
int main()
{
//	foo(0);
//	goo(0);
	HowLong(foo, 0);
//	HowLong(goo, 0);

	HowLong(hoo, 1, 2);
	HowLong(koo);
}