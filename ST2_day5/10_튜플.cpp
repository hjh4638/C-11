#include <iostream>
using namespace std;


template<typename T, typename ... Types>
class xtuple : public xtuple<Types...>
{
public:
	T value;

	xtuple(){}
	xtuple(const T& a, Types ... args)
		: value(a), xtuple<Types...>(args...){

	}
	enum{ N = xtuple<Types...>::N + 1 };
};

template<typename T> class xtuple<T> // 부분전문화 버전
{
public:
	T value;

	xtuple(){}
	xtuple(const T& a) :value(a){}

	enum{ N = 1 };
};

template<typename T> int xtuple_size(T& a){ return T::N; }

template<int N, typename T, typename ... Types>
struct xtuple_type;

// 0번째 타입을 요구할때를 위한 부분 전문화
template<typename T, typename ... Types>
struct xtuple_type < 0, xtuple<T, Types ...> >
{
 	typedef T type;
	typedef xtuple < T, Types... > TupleType;
};

// 0이 아닌 경우
template<int N, typename T, typename ... Types>
struct xtuple_type < N, xtuple<T, Types ...>>
	: xtuple_type<N - 1, xtuple<Types...>>
{
};

// 튜플에서 값을 꺼내는 함수
template<int N, typename ... Types>
typename xtuple_type<N, xtuple<Types...>>::type xget(xtuple<Types...>& t)
{
	return ((xtuple_type<N, xtuple<Types...>
>::TupleType)t).value;
}

// xtuple_type을 확인하기 위한 함수
template<int N, typename T> void print_type(const T& a)
{
	cout << typeid(xtuple_type<N, T>::type).name() << endl;
}

int main()
{
	//									value
	//						value + 부모 멤버
	//			 value + 부모 멤버
	//	value + 부모 멤버
	xtuple<int, char, double, short> t4(1, 'c', 3.3, 4);

	// tuple 타입 알아내기
	print_type<0>(t4);

	// 숙제.. 값을 뽑아내는 것!!
	cout << xget<1>(t4) << endl;
}

// C++ template complete guide 책 21장에 function<> 만드는 소스 있습니다!!