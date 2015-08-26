#include <iostream>
using namespace std;

int main(){
	//const int c = 10; //컴파일 시간 상수, 매크로 처럼 동작한다.
	int n = 10;
	const int c = n; //런타임 상수, 실행시간에 변경 불가능하다는 의미.
	//int* p = &c;//?? 상수의 주소를 int*에 담기
				//error
	int* p = (int*)&c;//ok.. 또는 C++ const_cast<>도 ok
	*p = 20;
	cout << c << endl;
	cout << *p << endl;
}