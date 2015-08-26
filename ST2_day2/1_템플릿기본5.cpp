#include <iostream>
#include <typeinfo> //RTTI기술
using namespace std;

//템플릿을 만들때
//값(T)로 전달 받으면 : 배열 => 포인터
//					   함수 => 포인터
//					   로 암시적 형변환되어 전달됩니다.
//					   Argument Decay라 불리는 현상입니다.

//참조(T&)로 전달받으면 : 배열 => 배열, 함수 => 함수로 
//						 정확히 전달 됩니다.

//문자열은 포인터가 아니라 배열입니다.

//main : 함수
//&main : 함수주소
//하지만 함수는 함수포인터로 암시적 형변환됩니다.

template<typename T> void foo(T& a)
{
	// T가 무슨 타입으로 결정 되었는지 알고 싶다면 아래 처럼 확인
	cout << typeid(a).name() << endl;//또는 typeid(T).name()
}

int main(){
	int n = 0;
	int x[10];

	foo(n);
	foo(x);
	foo("abcd");
	foo(main);
}