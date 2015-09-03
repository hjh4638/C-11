#include <iostream>
using namespace std;

// Step 3. 검색 대상 타입의 일반화 - 템플릿 도입
//

// 모든 타입의 배열 [First, last) 사이에서 선형검색을 수행하는 함수
template<typename T> T* xfind(T* first, T* last, T c)
{
	while (first != last && *first != c)
		++first;
	return first == last ? 0 : first;
}
int main()
{
	double x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	double* p = xfind(x, x + 10, 5.0);

	cout << *p << endl;
}