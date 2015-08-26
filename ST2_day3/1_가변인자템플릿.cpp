#include <iostream>
using namespace std;

// args : 여러개의 인자를 나타낸다. "Parameter Pack"
int n = 0;

// 결국 아래 템플릿은 foo() 함수가 4개 생성됩니다.
// 인자 값을 꺼내려면 1번째 인자는 이름이 있는 변수로 받아야 한다.
template<typename T, typename ... Types> void foo(T value, Types ... args)
{
	//static int n = 0;
	++n;
	cout << n << " ";

	cout << typeid(T).name() << " : " << value << endl;
	
	foo(args...); // args : 3.3, 'a', "hello"
}

void foo(){}

int main()
{
	foo(1, 3.3, 'a', "hello"); // value : 1	args : 3.3, 'a', "hello"
}