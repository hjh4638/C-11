#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point()				:x(0), y(0){}
	Point(int a, int b) : x(a), y(b){}

	//��ȯ������
	Point(int a)		:x(a), y(0){}

	//��ȯ������
	operator int(){ return x; }
};

int main()
{
	Point p1;
	Point p2(1, 2);

	int n = 10;

	n = p2;
	p2 = n;

	cout << "end" << endl;
}