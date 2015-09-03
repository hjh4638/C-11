#include <iostream>
#include <vector>
#include <type_traits>
using namespace std;

// ���� ��Ÿ��
// 1. �迭���� begin()/end()�� ����
// 2. �׷��� �迭������ �Լ��� ���� ����
// 3. show������ is_array<>�� ����ؼ� �Լ� �����ε����� �ذ�

// C++11 ���ο� ��Ÿ��

/*
// �����̳� ����
template<typename T> auto begin(T& c)		{ return c.begin(); }
template<typename T> auto end(T& c)			{ return c.end(); }

// �迭 ����
template<typename T, int N>
auto begin(T(&arr)[N]){ return arr; }
template<typename T, int N>
auto end(T(&arr)[N]){ return arr + N; }

*/

// ��� �Լ� begin()/end()�� ������� ����
// �Ϲ� �Լ� begin()/end()�� �������

// �ϳ��� �Լ����� ��ü�� �����̳ʿ� �Ϲ� �迭�� ��� ó���� ���ְ�
// �ȴ�.
// is_array<T>() ���� �Լ� �����ε��� �ʿ� ���� �ȴ�.
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