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


// �̹� xtuple�� ���� �����Ƿ� ���ο� xtuple�� ������ ���� �κ�
// ����ȭ �ؾ� �մϴ�.
// template<typename T> class xtuple // ���ο� tuple
template<typename T> class xtuple<T> // �κ�����ȭ ����
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