struct Point
{
	int x, y;
};

Point p;
Point foo(){ return p; }

int main()
{
	int n1 = 10;

	int& r1 = n1; // ok..  C++ 참조는 lvalue를 참조 할 수 있다.
	//int& r2 = 10; // error C++ 참조는 rvalue를 참조 할 수 없다.

	Point p2;
	Point& r3 = p2;		// ok
	//Point& r4 = foo();  // error 임시객체는 rvalue 이다

	//const&는 rvalue를 가르킬 수 있다.
	const int& r5 = 10; //ok
	const Point& r6 = foo(); //ok
}