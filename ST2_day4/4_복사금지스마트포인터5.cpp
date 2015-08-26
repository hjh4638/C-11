#include <iostream>
using namespace std;

// �ȵ���̵� �����ӿ�ũ, Ÿ���� ���� ���¼ҽ�
// UniquePtr<> �̶�� �̸����� ���� ���� ����Ʈ������ ����

// C++ 11 ǥ�� : unique_ptr<> �̸����� ����
//				���� ���� + ������ ����(move) ���� ����

#include <memory>

int main()
{
	unique_ptr<int> p1(new int);
	unique_ptr<int[]> p2(new int[10]);

	//unique_ptr<int> p3 = p1; //error. �������

	unique_ptr<int> p3 = move(p1); // ok
}