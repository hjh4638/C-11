#include <iostream>
#include <vector>
#include <type_traits>
using namespace std;

// begin_end1번 소스 : C++98 style
// 아래 함수 : C++11의 새로운 문법을 사용한 코드 - 훨씬 간단해집니다.
template<typename T> void show(T& c)
{
	for (auto n : c)
	{
		cout << n << " ";
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