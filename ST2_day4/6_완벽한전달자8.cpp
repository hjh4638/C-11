#include <iostream>
using namespace std;

void foo(int&) { cout << "int&" << endl; }
void foo(int&&){ cout << "int&&" << endl; }

template<typename T> void Call(T&& a)
{
	// T&& 가 int&&로 결정되어도 a 자체는 lvalue이다.
	// 즉, "이름을 가지는 rvalue reference는 lvalue이다"

	// 아래 의미처럼 해야 합니다.
	/*
	if (is_rvalue_reference<T&&>::value)
		foo(static_cast<T&&>(a));
	foo(a);
	*/
	foo(forward<T&&>(a)); // forward는 위의 if문처럼 되어 있습니다.
}

int main()
{
	int n = 10;
	Call(n);  // 1
	Call(10); // 1
}