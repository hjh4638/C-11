#include <iostream>
using namespace std;

class Meter
{
	int value;
public:
	Meter(int n) : value(n){}

	void print() const { cout << value << endl; }
};

// ����� ���� ����� ���� �� ���� Ÿ���� �̸� ���� �Ǿ� �ֽ��ϴ�.
// unsigned long long �Ǵ� char*
Meter operator"" m(unsigned long long sz)
{
	return Meter(sz);
}

int main()
{
	float f = 3.4f; // f, s, l

	Meter aa = 3m; // operator""m(3)


	aa.print();
}