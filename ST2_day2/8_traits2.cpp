#include <iostream>
using namespace std;

// Traits 기술 : T의 다양한 속성(특질)을 컴파일 시간에 알아내는 기술

// T에 대해서 조사할 수 있는 메타함수

// 만드는 방법
// privary template : false 리턴 (value = false)라는 의미
// 부분 전문화 버전  : true 리턴(value = true)
template<typename T> struct IsPointer
{
	enum{value = false};
};
template<typename T> struct IsPointer<T*>
{
	enum{ value = true };
};

template<typename T> void foo(T a)
{
	if (IsPointer<T>::value)	cout << "포인터" << endl;
	else						cout << "포인터 아님" << endl;
}

int main()
{
	int n = 0;
	foo(n);
	foo(&n);
}