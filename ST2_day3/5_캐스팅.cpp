#include <iostream>
using namespace std;

// C ĳ������ ������

// ��κ� �����Ѵ�... �׷���.. �ʹ� �����ϰ� ���װ� ��������.
// 

int main()
{
	int n = 10;
	//double* p = &n; // error. ���� �ٸ� Ÿ���� �ּҴ� �Ͻ��� ��ȯ �ȵ�
					// ��, C������ ����.
	//double* p = (double*) &n; //����� ��ȯ - ok
	//*p = 3.4;

	const int c = 10;
	//int* p2 = &c; // error. ��� �ּҴ� ���� �����Ϳ� ���� �� ����.
	int* p2 = (int*)&c;
	*p2 = 20;

	cout << c << endl;
	cout << *p2 << endl;
}