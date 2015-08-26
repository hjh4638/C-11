#include <iostream>
using namespace std;

//0,1로 함수 오버로딩이 되게 하는 기술

//모든 int형 상수를 타입으로 만드는 시스템
//Modern C++의 저자인 Andrei Alexandr.. 가 2000년도에 만든기술

//컴파일 시간 결정된 모든 상수는 함수 오버로딩에 활용될 수 있다.
template<int N> struct int2type
{
	enum{ value = N };
};
template<typename T> struct IsPointer
{
	enum{ value = false };
};
template<typename T> struct IsPointer<T*>
{
	enum{ value = true };
};

//포인터인 경우를 처리하는 함수
template<typename T> void printv_imp(T a, int2type<1>)
{
	cout << a << ", " << a << endl;
}
//포인터가 아닌 경우
template<typename T> void printv_imp(T a,int2type<0>)
{
	cout << a << endl;
}

//사용자가 사용하는 버전
template<typename T> void printv(T a)
{
	printv_imp(a, int2type<IsPointer<T>::value>());
}

int main(){
	int n = 3;
	printv(&n);
}
//int main
//{
//	foo(0);
//	foo(1);
//	int2type<0> t0;
//	int2type<1> t1;
//	foo(t0);
//	foo(t1); //t0와 t1은 다른 타입니다.
//			 //foo(t0), foo(t1)은 다른 함수 호출
//}

