#include <iostream>
using namespace std;

// Point p; => 이름 있는 객체 p, 블럭을 벗어날때 까지 생존
// Point() => 이름 없는 임시객체 생성. 현재 문장에서만 유효..


class Point
{
	int x, y;
public:
	Point(){ cout << "생성자" << endl; }
	~Point(){ cout << "소멸자" << endl; }
	
	Point(const Point&){ cout << "복사생성자" << endl; }
};

int main()
{
	cout << "AAA" << endl;
	//Point p;
	
	Point(); // 클래스이름()

	cout << "BBB" << endl;
}