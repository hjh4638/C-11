#include <iostream>
using namespace std;

// �Ϲ�ȭ(Generic) ���α׷���
// �ϳ��� �Լ�/Ŭ������ �ִ��� Ȱ�� ������ �е��� ����� ���� ��.
// �ϳ��� �Լ��� �پ��� ��츦 ó���ϵ��� ����!

// Step 2. �˻� ������ �Ϲ�ȭ - �κ� ���ڿ� �˻��� �����ϵ��� ����

// [first, last) ������ �κ� ���ڿ� �˻�
char* xstrchr(char* first, char* last, char c)
{
	while (first!=last && *first!=c)
		++first;
	return first == last ? 0 : first;
}
int main()
{
	char s[] = "abcdefgh";

	char* p = xstrchr(s, s+2, 'c');

	if (p == 0)
		cout << "ã�� �� �����ϴ�." << endl;
	else
		cout << *p << endl;
}