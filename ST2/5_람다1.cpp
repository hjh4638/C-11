//1. 인라인 함수와 함수 포인터 관계
//핵심 1. 인라인 치환은 컴파일 시간 문법이다.
//	   2. 
#include <iostream>
using namespace std;
	   int Add1(int a, int b){ return a + b; }
inline int Add2(int a, int b){ return a + b; }

int main(){
	int n1 = Add1(1, 2); // 호출
	int n2 = Add2(1, 2); // 기계어 코드 치환 - 속도가 빨라진다.
	
	int(*f)(int, int);

	f = &Add2;
	//--------------------
	/*int n = 0;
	cin >> n;
	if (n == 1) f = &Add1;*/
	//--------------------
	int n3 = f(1, 2); // 인라인 치환 안됨.
}