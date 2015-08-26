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
	enum{ N = xtuple<Types...>::N +1 };
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

	enum{N = 1};
};

template<typename T> int xtuple_size(T& a)
{
	return T::N;
}

int main()
{
	xtuple<int, char, double, short> t4(1, 'c', 3.3, 4);
	xtuple<int> t1(3);
	xtuple<int> t;
}