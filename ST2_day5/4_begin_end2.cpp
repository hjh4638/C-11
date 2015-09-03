#include <iostream>
#include <vector>
#include <type_traits>
using namespace std;

// 기존 스타일
// 1. 배열에는 begin()/end()가 없다
// 2. 그래서 배열버전의 함수를 따로 만들어서
// 3. show에서는 is_array<>를 사용해서 함수 오버로딩으로 해결

// C++11 새로운 스타일

/*
// 컨테이너 버전
template<typename T> auto begin(T& c)		{ return c.begin(); }
template<typename T> auto end(T& c)			{ return c.end(); }

// 배열 버전
template<typename T, int N>
auto begin(T(&arr)[N]){ return arr; }
template<typename T, int N>
auto end(T(&arr)[N]){ return arr + N; }

*/

// 멤버 함수 begin()/end()를 사용하지 말고
// 일반 함수 begin()/end()를 사용하자

// 하나의 함수에서 객체형 컨테이너와 일반 배열을 모두 처리할 수있게
// 된다.
// is_array<T>() 등의 함수 오버로딩이 필요 없게 된다.
template<typename T> void show(T& c)
{
	auto p = begin(c);

	while (p != end(c))
	{
		cout << *p << " ";
		++p;
	}
	cout << endl;
}

int main()
{
	int x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int> v(x, x + 10);

	show(v);
	show(x);

	int a = 1;
}