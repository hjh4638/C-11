#include <iostream>
using namespace std;

int main()
{
	int n = 10;
	int* p = &n;

	decltype(*p) n2 = *p; // n2�� ����Ÿ���ϱ��? ??? �� �����غ�����
					// ��Ʈ ����Ʈ ������ ���� �� �����غ�����
					// int& �Դϴ�.
	
	auto n3 = *p; // n3�� int


	//�߿�
	decltype(auto) n4 = *p; // �캯�� ���� �߷��ϴµ�
							// �߷� ����� decltype���� �ش޶�
}