#include <iostream>
using namespace std;

template<typename T> class my_reference_wrapper
{
	T* obj;
public:
	my_reference_wrapper(T& r) : obj(&r){}
	operator T&(){ return *obj; }
};

// 클래스 템플릿은 암시적 인자 추론이 불가능해서 항상 어려워 보입니다.
// 암시적 인자 추론이 가능한 함수 템플릿으로 Helper를 만들면
// 쉬워 집니다.
template<typename T> 
my_reference_wrapper<T> xref(T& a)
{
	return my_reference_wrapper<T>(a);
}

void foo(int a){ cout << "foo" << endl; }
void goo(int& a){ cout << "goo" << endl; a = 20; }

template<typename F, typename T>
void HowLong(F f, T a)
{
	f(a);
}


int main()
{
	int n = 0;

	goo(n); // goo를 직접 사용

//	my_reference_wrapper<int> r1 = n;
//	HowLong(goo, r1);

	// 임시객체로 만들어서 전달
	HowLong(goo, xref(n));

	cout << n << endl; // 20
}

//template<typename T> T square(T a){ reutnr a*a; }
//
//// 다음중 쉬운것은 ?
//square(3);		//1 쉬워 보인다 - 암시적 추론
//square<int>(3);	//2 어려워 보임 - 명시적 추론
//
//
//// 클래스 템플릿은 암시적 형변환 안됨
//list<int> s(10, 3); // 10개를 3으로!!!