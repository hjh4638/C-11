// 3_iterator_category

#include <iostream>
#include <list>
#include <algorithm> // fine() ���� �Լ��� ���� �ֽ��ϴ�.
using namespace std;

int main()
{
	list<int> s;
	s.push_back(10);
	s.push_back(20);

	// STL �Լ��� : �پ��� Ÿ�Կ� ����Ǵ� �Ϲ�ȭ �Լ�
	//				fine()�� ������ �迭, list, vector���
	//				����� �� �ִ�.

	sort(s.begin(), s.end());
}