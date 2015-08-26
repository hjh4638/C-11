#include <iostream>
using namespace std;

class Point{
	int x, y;
public:
	Point(int a = 0, int b = 0) :x(a), y(b){}

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