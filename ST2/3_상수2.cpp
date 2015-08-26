#include <iostream>
using namespace std;

//C89 : 배열의 크기는 컴파일 시간 상수만 된다.
//C99 : 배열의 크기는 변수도 가능하다. gcc 지원, VC++ 지원 안함
int main(){
	int x1[3];

	int s2 = 3;
	//int x2[s2];// gcc ok.. vc:error

	const int s3 = 3;
	int x3[s3];// ok..

	const int s4[] = { 1, 2, 3 };
	int x4[s4[1]];//int x4[*(s4+1)] 결국 배열 (s4)은 포인터 이므로
}


void foo(const int s){
	int x[s];//될까요? error
}