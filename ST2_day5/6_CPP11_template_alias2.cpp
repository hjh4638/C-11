#include <type_traits>
using namespace std;

// const�� ������ Ÿ���� ���ϴ� traits
template<typename T> struct xremove_const
{
	typedef T type;
};

template<typename T> struct xremove_const<const T>
{
	typedef T type;
};

// ��ó�� traits�� ����� ����
// using���� ����ϱ� ���� ���ָ� �˴ϴ�.
//
template<typename T>
using xremove_const_t = typename xremove_const<T>::type;

template<typename T> void foo(T& a)
{
	// T ���� const�� ������ Ÿ���� ���ϴ� ���
	// typename remove_const<T>::type n; // C++11 style

	xremove_const_t<T> n; // �� �� ������ ǥ���Դϴ�. // C++14 style
}

int main()
{
	int const c = 0;
	foo(c);
}