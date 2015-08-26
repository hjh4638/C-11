#include <iostream>
using namespace std;

class Point{
	int x, y;
public:
	Point(int a, int b){}
};

int main(){
	// 1. 힙에 Point 한개를 만들어 보세요..
	Point* a1 = new Point(1, 2);
	// 2. 힙에 Point 10개를 만들어 보세요..
	//Point* p2 = new Point[10]; // 힘들다!!

	//해결책 : 메모리 할당과 생성자 호출을 분리하면 편리해 진다.
	Point* p3 = static_cast<Point*>(operator new(sizeof(Point) * 10));

	//할당된 메모리의 생성자를 호출해서 객체를 초기화 한다.
	for (int i = 0; i < 10; i++){
		new(&p3[i]) Point(0, 0);
	}

	//이경우 소멸자 호출 및 메모리 해지도 아래처럼 해야한다.
	for (int i = 9; i >= 0; i--){
		p3[i].~Point();
	}
	operator delete(p3);

	// Point를 스택에 10개 만들어 보세요
	char buf[sizeof(Point) * 10];
	Point* p4 = reinterpret_cast<Point*>(&buf);

	//p4에 대해 생성자를 명시적으로 호출하고 사용하면 된다.
	//사용후 소멸자도 명시적으로 호출해야 한다.
}