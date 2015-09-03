#include <iostream>
using namespace std;

void foo(int&& k, int&& q) { cout << "foo" << endl; }

// 4. rvalue �� �������ڷ� ���޵Ǹ� Types&& �� rvalue_reference�̴�
//	  ������ args... ��ü�� �̸��ִ� rvalue reference �̹Ƿ�
//	  lvalue�� �ȴ�.
//	  forward<>�� ����� �Ѵ�.

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