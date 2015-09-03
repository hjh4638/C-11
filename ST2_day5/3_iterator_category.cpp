// 3_iterator_category

#include <iostream>
#include <list>
#include <algorithm> // fine() 같은 함수가 여기 있습니다.
using namespace std;

int main()
{
	list<int> s;
	s.push_back(10);
	s.push_back(20);

	// STL 함수들 : 다양한 타입에 적용되는 일반화 함수
	//				fine()를 가지고 배열, list, vector등에서
	//				사용할 수 있다.

	sort(s.begin(), s.end());
}