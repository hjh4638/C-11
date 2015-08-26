#include <iostream>
using namespace std;

// 규칙 3. Universal reference 인 경우
// int&& : rvalue reference - rvalue 만 담을 수 있다.
// T&& : universal reference ( forward reference 라고도 합니다.)

// 인자로 전달되는 표현이 lvalue 이면 T&&는 lvalue reference 가 되고
// 인자로 전달되는 표현이 rvalue 이면 T&&는 rvalue reference 가 된다.
template<typename T> void foo(T&& a)
{

}

int main()
{
	int n = 10;
	foo(n);
	foo(10);

	int& r = n;
	foo(r);
}