#include <iostream>
using namespace std;

//1. new의 정확한 동작 방식
//	 (A) operator new() 함수를 사용해서 메모리 할당
//	 (B) (A)가 성공하고 객체라면 생성자 호출
//	 (C) 메모리 주소를 해당 타입으로 캐스팅해서 리턴.

//2. new 와 operator new()는 다른 요소이다.!!

class Point{
	int x, y;
public:
	Point(){ cout << "생성자" << endl; }
	~Point(){ cout << "소멸자" << endl; }
};

int main(){

	//생성자 호출없이 메모리 할당만 하는 방법
	Point* p = static_cast<Point*>(operator new(sizeof(Point)));
	operator delete(p);

	//Point* p = new Point;
	//delete p;

}