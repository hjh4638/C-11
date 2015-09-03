#include <iostream>
using namespace std;

struct Point3D
{
	int x, y, z;
};

// 사용자 정의 타입에 대해 ranged-for를 사용하려면
// begin()/end()를 만들면 된다.
int* begin(Point3D& p)	{ return &(p.x); }
int* end(Point3D& p)	{ return &(p.z)+1; }

int main()
{
	Point3D pt = { 1, 2, 3 };

	for (auto n : pt) // 될까요?
	{
		cout << n << endl;
	}
}