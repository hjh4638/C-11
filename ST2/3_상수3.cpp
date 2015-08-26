#include <iostream>
using namespace std;


constexpr int foo( int a,  int b){
	return a + b;// 컴파일러는 컴파일 시간에 상수 덧셈을 할 수 있으므로..
}
int main(){
	int n = 10;

	//C++98/03 스타일 : 1998년 표준화 되고 2003년 개정된 C++
	const int c1 = 10;
	const int c2 = n;

	//C++11/14 : 2011년 2차 표준화 2014년 버그수정(개정판)
	constexpr int c3 = 10;
	//constexpr int c4 = n;
	
	//배열 크기로 함수도 사용가능, 단 함수리턴값은 __이어야한다.
	constexpr int a = 1;
	constexpr int b = 4;
	int x[foo(a,b)];
}