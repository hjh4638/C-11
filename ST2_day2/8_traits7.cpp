#include <iostream>
using namespace std;

#include <type_traits> //이안에 integral_constant<>와
					   //is_pointer<> 등의 100여개 traits가 있습니다.

void check(true_type){ cout << "check : 포인터" << endl; }
void check(false_type){ cout << "check : 포인터 아님" << endl; }
template<typename T> void foo(const T& a)
{
	//traits 사용방법 1. value 꺼내서 조사
	//단점 : 포인터가 아닌 else문 안에서 *a 등의 표현이 있으면 안된다.
	if (is_pointer<T>::value){
		cout << "포인터" << endl;
	}
	else
		cout << "포인터 아님" << endl;

	//2. 함수 오버로딩
	//장점 : 포인터와 포인터 아닌 경우가 별개의 함수로 처리됨
	//		*a등의 표현 가능
	check(is_pointer<T>());
}

int main()
{
	int n = 10;
	foo(&n);
	foo(n);
}