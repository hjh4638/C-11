#include <iostream>
using namespace std;

// 안드로이드 프레임워크, 타이젠 등의 오픈소스
// UniquePtr<> 이라는 이름으로 복사 금지 스마트포인터 제공

// C++ 11 표준 : unique_ptr<> 이름으로 제공
//				복사 금지 + 소유권 이전(move) 개념 지원

#include <memory>

int main()
{
	unique_ptr<int> p1(new int);
	unique_ptr<int[]> p2(new int[10]);

	//unique_ptr<int> p3 = p1; //error. 복사금지

	unique_ptr<int> p3 = move(p1); // ok
}