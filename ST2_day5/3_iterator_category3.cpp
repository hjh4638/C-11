#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

// 반복자 카테고리
// 1. 입력 반복자		: =*p, ++
// 2. 출력 반복자		: *p=, ++
// 3. 전진형 반복자		: 입출력, ++						싱글리스트
// 4. 양방향 반복자		: 입출력 --						더블리스트
// 5. 임의 접근 반복자	: 입출력, ++, --, +, -, []		연속된 메뫼리

int main()
{
	int x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int* p = find(x, x + 10, 5); // 1,2, 번째 인자는 반복자 입니다.
								 // 최소 요구조건을 생각해 보세요.
								 // 입력 반복자

	reverse(x, x + 10); // 최소조건 - 양방향 반복자

	sort(x, x + 10); // 퀵소트입니다. - 임의 접근 반복자
	//-----------------------------
	
	slist<int> s; // 우리가 만든 slist

	reverse(s.begin*()(e.end()); // 될까요?

	list<int> s2;
	sort(s2.begin(), s2.end()); // ?
	s2.sort(); // 일반화 함수 sort()를 사용할 수 없기 때문에
			   // 멤버 함수 sort()가 있습니다.
			  // 퀵이 아닌 다른 알고리즘 사용

	vector<int> v; 
	v.sort(); // 이 멤버 함수가 있을까요? 없다
			  // vector의 반복자는 임의접근반보개:

	sort
}