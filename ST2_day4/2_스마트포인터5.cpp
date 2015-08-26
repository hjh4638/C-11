#include <iostream>
using namespace std;

// 이미 C++표준에 참조계수 스마트 포인터가 있습니다.
#include <memory>
using namespace td;

int main()
{
	shared_ptr<int> p1(new int);

	shared_ptr<int> p2 = p1; // 이순간 참조계수가 증가합니다.
}