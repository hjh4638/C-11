#include <iostream>
using namespace std;

void foo(int&& k, int&& q) { cout << "foo" << endl; }

// 4. rvalue 가 가변인자로 전달되면 Types&& 은 rvalue_reference이다
//	  하지만 args... 자체는 이름있는 rvalue reference 이므로
//	  lvalue가 된다.
//	  forward<>로 묶어야 한다.

template<typename F, typename ... Types>
decltype(auto) HowLong(F f, Types&& ... args)
{
	return f(forward<Types&&>(args)...);
	// f(forward<T&&>(0), forward<T&&>(0));
}

int main()
{
	foo(0, 0);

	HowLong(foo, 0, 0);
}