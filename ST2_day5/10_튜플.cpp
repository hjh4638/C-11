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

template<typename T> class xtuple<T> // �κ�����ȭ ����
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

// 0��° Ÿ���� �䱸�Ҷ��� ���� �κ� ����ȭ
template<typename T, typename ... Types>
struct xtuple_type < 0, xtuple<T, Types ...> >
{
 	typedef T type;
	typedef xtuple < T, Types... > TupleType;
};

// 0�� �ƴ� ���
template<int N, typename T, typename ... Types>
struct xtuple_type < N, xtuple<T, Types ...>>
	: xtuple_type<N - 1, xtuple<Types...>>
{
};

// Ʃ�ÿ��� ���� ������ �Լ�
template<int N, typename ... Types>
typename xtuple_type<N, xtuple<Types...>>::type xget(xtuple<Types...>& t)
{
	return ((xtuple_type<N, xtuple<Types...>
>::TupleType)t).value;
}

// xtuple_type�� Ȯ���ϱ� ���� �Լ�
template<int N, typename T> void print_type(const T& a)
{
	cout << typeid(xtuple_type<N, T>::type).name() << endl;
}

int main()
{
	//									value
	//						value + �θ� ���
	//			 value + �θ� ���
	//	value + �θ� ���
	xtuple<int, char, double, short> t4(1, 'c', 3.3, 4);

	// tuple Ÿ�� �˾Ƴ���
	print_type<0>(t4);

	// ����.. ���� �̾Ƴ��� ��!!
	cout << xget<1>(t4) << endl;
}

// C++ template complete guide å 21�忡 function<> ����� �ҽ� �ֽ��ϴ�!!