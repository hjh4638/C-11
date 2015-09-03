#include <iostream>
using namespace std;

int g_x = 0;
int& foo(int a, int& b){ cout << "foo" << endl; b = 10; return g_x; }

// 1. 함수 인자의 갯수는 다양하다 - 가변인자 템플리승로 하자
template<typename F, typename ... Types> 
void HowLong(F f, Types ... args)
{
	f(args...);
}

int main()
{
	int x = 0;
	HowLong(foo, 1, x);
}