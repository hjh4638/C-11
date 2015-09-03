#include <iostream>
#include <assert.h>
using namespace std;

// 기존 assert() 실행시간 동작하는 함수
void foo(int age)
{
	// 인자를 무조건 사용하지 말고
	// 인자 값이 유효한지를 먼저 확인하는 것이 좋다.
	assert(age > 0); // 조건을 만족하지 않으면 abort()를 호출하고
					 // 종료 된다.
	char* p = new char[age];
}
int main()
{
	foo(-10);
}