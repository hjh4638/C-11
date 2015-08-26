#include <iostream>
using namespace std;
template<typename T> void print(const T& d)
{
	cout << T::N << endl;
}

template<typename T, typename U> struct Duo
{
	T value1;
	U value2;
	enum{N=2};
};

//Duo의 2번째 인자가 다시 Duo일때(Recursive)를 위한 부분전문화
//부분 전문화 할때 템플릿 인자 갯수가 바뀌어도 됩니다.
template<typename A, typename B, typename C> 
struct Duo <A, Duo<B, C>>
{
	A value1;
	Duo<B,C> value2;
	enum{ N = Duo<B,C>::N +1 };
};

//1번째가 다시 Duo일때
template<typename A, typename B, typename C>
struct Duo <Duo<B, C>, A>
{
	A value1;
	Duo<B, C> value2;
	enum{ N = Duo<B, C>::N + 1 };
};

template<typename A, typename B, typename C, typename D>
struct Duo <Duo<A, B>, Duo<C,D>>
{
	Duo<A, B> value1;
	Duo<C, D> value2; 
	enum{ N = Duo<A, B>::N + Duo<C, D>::N };
};


int main()
{
	
	//Duo<int, int> d2;
	/*Duo<int, Duo<int,int>> d3;
	Duo<int, Duo<int, Duo<int, int>>> d4;
	print(d3);
	print(d4);*/

	//1번째 인자가 Duo일때
	//Duo<Duo<int, int>, int> d3;
	//Duo < Duo<Duo<int, int>, int>, int> d4;
	//print(d3);
	//print(d4);

	Duo < Duo<int, int>, Duo<int, int>> d4;
	print(d4);
}
//typedef Duo<int, int> Point;