#include <iostream>
using namespace std;

int a;
int* p;
int x[10]; //int[10] 가 x의 타입이다
		   //T[N]
//traits 만드는 법 다시 정리

// primary template : false_type을 기본 클래스로
// 부분 전문화 버전 : true_type을 기본 클래스로
template<typename T> struct IsArray : false_type{
	static const int size = -1; // 배열이 아니므로
};
template<typename T, int N> struct IsArray<T[N]> : true_type{
	static const int size = N;
};
template<typename T> void foo(const T& a)
{
	if (IsArray<T>::value)
	{
		cout << "배열, 크기는" << IsArray<T>::size<< endl;
	}
	else
	{
		cout << "배열 아님" << endl;
	}
}

int main()
{
	int x[10];
	foo(x);
}