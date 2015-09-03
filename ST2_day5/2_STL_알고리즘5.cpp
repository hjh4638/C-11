#include <iostream>
using namespace std;

// Step 5. ������ ����

// ��� Ÿ���� �迭 [first, last) ������ ��������
// �����˻��� �����ϴ� �Լ�

// last�� �˻��� ���Ե����� �ʴ´� - past the end��� �θ���

// ������ ��� last�� �����Ѵ�.

template<typename T1, typename T2>
T1 xfind(T1 first, T1 last, T2 c)
{
	while (first != last && *first != c)
		++first;
	return first; // == last ? 0 : first;
}
int main()
{
	double x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	double* p = xfind(x, x + 15, 15);

	if (p == x+15 ) cout << "ã�� �� ����" << endl;
	cout << *p << endl;
}