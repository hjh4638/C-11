// 1_��ȯ4
#include <iostream>
using namespace std;

int main()
{
	int n = 0;

	while (1)
	{
		cin >> n; //'a' �� �Է����Ŀ� enter..

		if (cin.fail())
		{
			cout << "�ٽ� �Է��ϼ���" << endl;
			cin.clear(); // ���������� �����Ǵ� state
						// ����� reset �� �� �ٽ� �Է¹޾ƾ� �Ѵ�.
			cin.ignore(); // �Է� ���۸� �����.

			continue;
		}
		break;
	}
	cout << n << endl; // 1. 10  2. 97  3. 0  4. -1
}