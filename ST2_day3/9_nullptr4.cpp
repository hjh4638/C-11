#include<iostream>
using namespace std;

// nullptr�� nullptr_t Ÿ�� �Դϴ�.

int main()
{
	nullptr_t n = nullptr;

	int* p = nullptr;			// nullptr_t => ��� ������ Ÿ������ �Ͻ�����ȯ
	//int  a = nullptr;			// nullptr�� int�� �Ͻ��� ����ȯ �ȵ�.
	bool b = nullptr;			//ok
}