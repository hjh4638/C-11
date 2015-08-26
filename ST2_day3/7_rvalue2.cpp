struct Point
{
	int x, y;
};

Point p;
Point foo(){ return p; }

int main()
{
	int n1 = 10;

	int& r1 = n1; // ok..  C++ ������ lvalue�� ���� �� �� �ִ�.
	//int& r2 = 10; // error C++ ������ rvalue�� ���� �� �� ����.

	Point p2;
	Point& r3 = p2;		// ok
	//Point& r4 = foo();  // error �ӽð�ü�� rvalue �̴�

	//const&�� rvalue�� ����ų �� �ִ�.
	const int& r5 = 10; //ok
	const Point& r6 = foo(); //ok
}