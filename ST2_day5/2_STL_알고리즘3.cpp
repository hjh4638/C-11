#include <iostream>
using namespace std;

// Step 3. �˻� ��� Ÿ���� �Ϲ�ȭ - ���ø� ����
//

// ��� Ÿ���� �迭 [First, last) ���̿��� �����˻��� �����ϴ� �Լ�
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