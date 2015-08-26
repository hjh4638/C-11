#include <iostream>
using namespace std;

//논리적 상수성 : 외부에서 바라볼때는 상수 함수가 되야하지만 내부적으로는 멤버 변수의 값을 변경해야 하는 문제
// 1. 변하는 멤버는 mutable로 !!
class Point{
	int x, y;
	mutable char cache[32];
	mutable bool cache_valid;
public:
	Point(int a = 0, int b = 0) :x(a), y(b), cache_valid{false){}

	//객체의 상태를 문자열로 반환하는 함수 : java, C#에 있는 개념
	char* toString() const
	{
		static char s[32];
		sprintf_s(s, "%d %d", x, y);
		return s;
	}
};
int main(){
	Point p(1, 2);
	cout << p.toString() << endl;
	cout << p.toString() << endl;
}