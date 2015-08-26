// 1_변환4
#include <iostream>
using namespace std;

int main()
{
	int n = 0;

	while (1)
	{
		cin >> n; //'a' 를 입력한후에 enter..

		if (cin.fail())
		{
			cout << "다시 입력하세요" << endl;
			cin.clear(); // 내부적으로 관리되는 state
						// 멤버를 reset 한 후 다시 입력받아야 한다.
			cin.ignore(); // 입력 버퍼를 지운다.

			continue;
		}
		break;
	}
	cout << n << endl; // 1. 10  2. 97  3. 0  4. -1
}