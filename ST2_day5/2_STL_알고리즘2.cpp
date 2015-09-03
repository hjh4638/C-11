#include <iostream>
using namespace std;

// 일반화(Generic) 프로그래밍
// 하나의 함수/클래스를 최대한 활용 범위가 넓도록 만들어 가는 것.
// 하나의 함수로 다양한 경우를 처리하도록 하자!

// Step 2. 검색 범위의 일반화 - 부분 문자열 검색이 가능하도록 하자

// [first, last) 사이의 부분 문자열 검색
char* xstrchr(char* first, char* last, char c)
{
	while (first!=last && *first!=c)
		++first;
	return first == last ? 0 : first;
}
int main()
{
	char s[] = "abcdefgh";

	char* p = xstrchr(s, s+2, 'c');

	if (p == 0)
		cout << "찾을 수 없습니다." << endl;
	else
		cout << *p << endl;
}