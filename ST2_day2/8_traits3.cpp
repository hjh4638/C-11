#include <iostream>
using namespace std;
template<typename T> struct IsPointer
{
	enum{ value = false };
};
template<typename T> struct IsPointer<T*>
{
	enum{ value = true };
};

// 컴파일러의 동작 방식
// 1. T를 결정해서 함수 생성
// 2. 생성된 함수 컴파일
// 3. 실행되지 않은 코드 제거
template<typename T> void printv(T a)
{
	if (IsPointer<T>::value)
		cout << a << ", " << *a << endl;
	else
		cout << a << endl;
}
int main()
{
	int n = 3;
	printv(n);//이 경우가 문제가 된다.
	//printv(&n);//이 경우는 ok
}