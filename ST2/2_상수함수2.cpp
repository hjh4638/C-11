#include <iostream>
using namespace std;
//핵심:상수 함수는 필수이다.
//객체의 상태를 변경하지 않은 모든 멤버 함수는 반드시 상수함수로 만들어야한다.

//void foo(const Rect& r) 코드에서 r에 대하여 면적은 구할 수 있어야 한다!!
class Rect{
	int x, y, w, h;
public:
	int getArea()const{ return w*h; }
};

//C++ 기본 기법 : call by value 대신 const &가 좋다.!!
void foo(const Rect& r){
	int n = r.getArea();
}
int main(){
	Rect r;//초기화 했다고 가정하고
	int n = r.getArea();//ok..
	foo(r);
}