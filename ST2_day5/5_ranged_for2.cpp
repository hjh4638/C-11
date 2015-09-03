#include <iostream>
using namespace std;

struct Point3D
{
	int x, y, z;
};

// ����� ���� Ÿ�Կ� ���� ranged-for�� ����Ϸ���
// begin()/end()�� ����� �ȴ�.
int* begin(Point3D& p)	{ return &(p.x); }
int* end(Point3D& p)	{ return &(p.z)+1; }

int main()
{
	Point3D pt = { 1, 2, 3 };

	for (auto n : pt) // �ɱ��?
	{
		cout << n << endl;
	}
}