#include <iostream>
using namespace std;

class Point{
public:
	int x, y;

	Point(int a = 0, int b = 0) :x(a), y(b){}
	void set(int a, int b){ x = a; y = b; }

	void printf() const
	{
		cout << x << ", " << y << endl;
		//x = 10; //상수 함수 안에서는 멤버 값을 변경할 수 없다.
		cout << x << ", " << y << endl;
	}
};

int main(){
	const Point p(0, 0);
	p.x = 10;//error
	p.set(10, 10);//?error

	p.printf();//호출되게 하려면 printf()는 상수함수 이어야한다.
	//"상수 객체는 상수 함수만 호출가능하다"
}