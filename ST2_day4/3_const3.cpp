#include <iostream>
using namespace std;

int main()
{
	int n = 10;

	const int* p1 = &n; // p1�� const �ƴ�. p1�� ���󰡸� const 
	int* const p2 = &n; // p2�� const. p2�� ���󰡸� const �ƴ�.

	// p1�� ����Ű�� ���� r1�� ����� ������.
	// p2�� ����Ű�� ���� r2�� ����� ������.

	const int*& r1 = p1; // ����� ����Ű�� ������ ����
	int* const& r2 = p2; // ���������(������ ��ü�� ���)�� ����

	// ��Ʈ : int�� ������ int&�Դϴ�

}