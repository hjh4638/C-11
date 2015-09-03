#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	
	vector<int> v(x, x + 10);

	//for (auto n : x) // ranged - for ��..
	for (auto n : v)
	{
		cout << n << endl;
	}

	// �� �ڵ带 ������ �ϸ� �Ʒ� �ڵ尡 �˴ϴ�.
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