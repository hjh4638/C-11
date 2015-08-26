#include <iostream>
using namespace std;

//C++ 표준위원회는 int2type을 발전시켜서 아래 템플릿을 제공합니다.
template<typename T, T N> struct integral_constant
{
	//enum{ value = N };
	static const T value = N; //static const는 클래스안에서
							//바로 초기화 가능합니다. 2000년중반에
							// 추가된 문법
							// 그래서 요즘은 enum 대신 사용합니다.
};
//integral_constant<int, 0 >  n0;
//integral_constant<short, 0> s0;

//true/false		   : 참거짓을 나타내는 값   - 같은 타입
//true_type/false_type : 참거짓을 나타내는 타입 - 다른 타입
typedef integral_constant<bool, true>  true_type;
typedef integral_constant<bool, false> flase_type;

//이제 is_pointer 등을 만들때 아래 처럼 합니다.
//상속의 개념이 추가되고, value는 부모로부터 물려받습니다.
//template<typename T> struct is_pointer    : false_type{};
//template<typename T> struct is_pointer<T*> : true_type{};

#include <type_traits>
//포인터인 경우를 처리하는 함수
template<typename T> void printv_imp(T a, true_type)
{
	cout << a << ", " << a << endl;
}
//포인터가 아닌 경우
template<typename T> void printv_imp(T a, false_type)
{
	cout << a << endl;
}

//사용자가 사용하는 버전
template<typename T> void printv(T a)
{
	printv_imp(a, is_pointer<T>());
}

int main(){
	int n = 3;
	printv(&n);
}