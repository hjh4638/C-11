#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	
	vector<int> v(x, x + 10);

	//for (auto n : x) // ranged - for 문..
	for (auto n : v)
	{
		cout << n << endl;
	}

	// 위 코드를 컴파일 하면 아래 코드가 됩니다.
	for (auto p = begin(v); p != end(v); ++p)
	{
		auto n = *p;
		cout << n << endl;
	}

	/*
	for (int i = 0; i < 10; i++)
	{
		cout << x[i] << endl;
	}
	*/
}