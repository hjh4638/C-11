#include <iostream>
#include <vector>
#include <type_traits>
using namespace std;

// �����̳��� ��� ��Ҹ� ȭ�鿡 ����ϴ� �Լ�
template<typename T> void showImpl(T& c, false_type)
{
	typename T::iterator p = c.begin();

	while (p != c.end())
	{
		cout << *p << " ";
		++p;
	}
	cout << endl;
}

// �迭�� ��
template<typename T> void showImpl(T& c, true_type)
{
	auto p = c; // �迭�� �̸��� ���� �ּ��̴�.

	while (p != c + extent<T,0>::value)
	{
		cout << *p << " ";
		++p;
	}
	cout << endl;
}
template<typename T> void show(T& c)
{
	showImpl(c, is_array<T>() );
}
int main()
{
	int x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int> v(x, x + 10);

	show(v);
	show(x);
}