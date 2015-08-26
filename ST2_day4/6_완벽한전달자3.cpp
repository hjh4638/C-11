#include <iostream>
using namespace std;

// 이동 가능한 참조 만들기 - 어려운 내용입니다.

// C++ 참조 : 값이 이동하는 참조.. 처음 초기화된 메모리를 
//			  계속 참조 한다. 다른 변수를 참조하게 바꿀 수 없다.

// 포인터 : 값이 아닌 주소의 이동, 가리키는 메모리가 변경된다.

// 참조는 결국 자동으로 역참조(*)되는 포인터 입니다.

// 이동 가능한 참조를 만들어 봅시다.
template<typename T> class my_reference_wrapper
{
	T* obj; // 메모리를 가리켜야 하므로 결국 포인터입니다.
public:
	my_reference_wrapper(T& r) : obj(&r){}

	// 진짜 참조와의 호환을 위해서 변환연산자 제공
	operator T&(){ return *obj; }
};
int main()
{
	int n1 = 10;
	int n2 = 20;

	//int& r1 = n1;
	//int& r2 = n2;
	
	my_reference_wrapper<int> r1 = n1;
	my_reference_wrapper<int> r2 = n2;

	r2 = r1; // 이 한줄의 결과를 예측해 보세요.
			 // 값 이동 ? 참조이동 ? 값 이동!!

	int& r3 = r1; // 진짜 참조와 호환되게 해보자
				  // 
	cout << r3 << endl;
	//					// 값 이동시		참조이동시
	cout << n1 << endl; // 10			10
	cout << n2 << endl; // 10			20
	cout << r1 << endl; // 10			10
	cout << r2 << endl; // 10			10

}