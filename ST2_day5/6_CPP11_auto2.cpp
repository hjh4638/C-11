#include <iostream>
using namespace std;

int main()
{
	int n = 10;
	int* p = &n;

	decltype(*p) n2 = *p; // n2는 무슨타입일까요? ??? 잘 생각해보세요
					// 힌트 스마트 포인터 만들 때 생각해보세요
					// int& 입니다.
	
	auto n3 = *p; // n3는 int


	//중요
	decltype(auto) n4 = *p; // 우변을 보고 추론하는데
							// 추론 방식은 decltype으로 해달라
}