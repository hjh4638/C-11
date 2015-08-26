// 1_변환
#include <iostream>
using namespace std;

// 변환 연산자 : 객체(Point) => 다른 타입(int)
// 변환 생성자 : 다른 타입(int) => 객체(Point)
class Point
{
	int x, y;
public:
	Point()					:x(0), y(0){}
	Point(int a, int b)		:x(a), y(b){}

	// 변환 생성자 : 인자가 한개인 생성자
	//				다른 타입이 객체로 암시적 형변환되게 한다.
	Point(int a) :x(a), y(0){}

	//변환 연산자 함수 : 객체를 다른 타입으로 암시적 형변환
	//					되도록 한다.
	//특징 : 함수 이름에 리터타입이 들어 있으므로 리턴 타입을
	//		표시하지 않는다.
	operator int(){ return x; }
};

int main()
{
	Point p1;
	Point p2(1, 2);

	int n = 10;

	n = p2; // Point => int 변환 : p2.operator int()가 필요
	p2 = n; // int => Point 변환 : n.operator Point()가 필요
			//				그런데 n은 사용자 타입이 아니다!
}

/*
int main()
{
	double d = 3.4;
	int n = d; // 기본 타입은 서로 암시적 형변환이 가능하다

	Point p(1, 2);
	n = p; // p.operator int() 함수가 있으면된다.!
}
*/