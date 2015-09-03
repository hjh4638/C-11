#include <iostream>
using namespace std;

// 위임 생성자 (delegating constructor)
class Point
{
public:
	int x = 0; // class 안에서 멤버 변수를 상수값으로 바로 초기화 가능
	int y = 0; // java C# 처럼
	int a{ 0 }; // 가장 권장하는 스타일

	Point(int a, int b) :x(a), y(b){}
	Point() : Point(0,0) // 생성자에서 다른 생성자를 호출하는 코드
	{
		//this(0,0)
		//Point(0, 0); // 생성자에서 다른 생성자 호출이 아니고
					 // 임시객체를 만드는 표현이다.
	}
};
int main()
{
	Point p;
	cout << p.x << endl;
}