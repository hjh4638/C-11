#include <iostream>
#include <vector>
#include <type_traits>
using namespace std;

// begin_end1�� �ҽ� : C++98 style
// �Ʒ� �Լ� : C++11�� ���ο� ������ ����� �ڵ� - �ξ� ���������ϴ�.
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