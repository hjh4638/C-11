#include <iostream>
using namespace std;

// �̹� C++ǥ�ؿ� ������� ����Ʈ �����Ͱ� �ֽ��ϴ�.
#include <memory>
using namespace td;

int main()
{
	shared_ptr<int> p1(new int);

	shared_ptr<int> p2 = p1; // �̼��� ��������� �����մϴ�.
}