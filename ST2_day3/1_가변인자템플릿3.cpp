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


// 이미 xtuple은 위에 있으므로 새로운 xtuple을 만들지 말고 부분
// 전문화 해야 합니다.
// template<typename T> class xtuple // 새로운 tuple
template<typename T> class xtuple<T> // 부분전문화 버전
{
public:
	T value;

	xtuple(){}
	xtuple(const T& a) :value(a){}

	enum{ N = 1 };
};

template<typename T> int xtuple_size(T& a){	return T::N;}

// xtuple의 가진 N번재 요소의 타입을 알아내는 기술 - 어렵습니다.!!

// 결국 아래의 primary 버전은 사용되지 않고..
// 부분 전문화 버전만 사용하게 됩니다.
// 이경우는 구조체 몸체 ({}) 없이
// 선언만 있어도 됩니다.
// 단, 선언자체는 꼭 있어야 부분전문화 버전을 만들 수 있습니다.
template<int N, typename T, typename ... Types>
struct xtuple_type;

// 0번째 타입을 요구할때를 위한 부분 전문화
template<typename T, typename ... Types>
struct xtuple_type < 0, xtuple<T, Types ...> >
{
	typedef T type;
};

// 0이 아닌 경우
template<int N, typename T, typename ... Types>
struct xtuple_type < N, xtuple<T, Types ...>>
	: xtuple_type<N-1, xtuple<Types...>>
{
};

// xtuple_type을 확인하기 위한 함수
template<int N, typename T> void print_type(const T& a)
{
	cout << typeid(xtuple_type<N, T>::type).name() << endl;
}

int main()
{
	xtuple<int, char, double, short> t4(1, 'c', 3.3, 4);

	// tuple 타입 알아내기
	print_type<0>(t4);

	// 숙제.. 값을 뽑아내는 것!!
	cout << xget<1>(t4) << endl;
}