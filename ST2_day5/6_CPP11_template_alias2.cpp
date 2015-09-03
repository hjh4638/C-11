#include <type_traits>
using namespace std;

// const를 제거한 타입을 구하는 traits
template<typename T> struct xremove_const
{
	typedef T type;
};

template<typename T> struct xremove_const<const T>
{
	typedef T type;
};

// 위처럼 traits를 만들어 놓고
// using으로 사용하기 쉽게 해주면 됩니다.
//
template<typename T>
using xremove_const_t = typename xremove_const<T>::type;

template<typename T> void foo(T& a)
{
	// T 에서 const를 제거한 타입을 구하는 방법
	// typename remove_const<T>::type n; // C++11 style

	xremove_const_t<T> n; // 위 와 동일한 표현입니다. // C++14 style
}

int main()
{
	int const c = 0;
	foo(c);
}