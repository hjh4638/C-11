#include <iostream>
using namespace std;

// C++은 4개의 캐스팅 연산자를 지원한다.

// static_cast : void* => 다른 타입은 허용
//					그 외에는 연관성이 있어야 한다.!!
// reinterpre_cast : 메모리의 재해석, 대부분 성공.
// const_cast :
// dynamic_cast : 

int main()
{
	int* p3 = static_cast<int*>(malloc(100));  // void* => int* 변환
											   // 
	int n = 10;
	//double* p = (double*) &n; //명시적 변환 - ok
	//double* p = static_cast<double*>(&n); // int* => double*
										// error
	double* p = reinterpret_cast<double*>(&n); //ok..

	const int c = 10;
	//int* p2 = (int*)&c;
	//int* p2 = static_cast<int*>(&c); // error
	//int* p2 = reinterpret_cast<int*>(&c); // error. 
										// 상수성 제거는 안됨.

	int* p2 = const_cast<int*>(&c); // ok.. 상수성 제거
	// 하지만 아래처럼 사용하면 역시 혼란스러워 집니다..
	*p2 = 20;

	cout << c << endl;
	cout << *p2 << endl;
}