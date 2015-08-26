#include <iostream>
using namespace std;

//bool 기반 type selection 기술
template<bool, typename T, typename U>
struct IfThenElse
{
	typedef T ResultT;
};
template<typename T, typename U>
struct IfThenElse<false, T, U>
{
	typedef U ResultT;
};

//primary template을 보면 템플릿인자는 3개입니다.
//IfThenElse<bool 상수, 타입, 타입>
template<typename T, typename U> 
typename IfThenElse<sizeof(T)>sizeof(U), T, U > ::Result
Mul(T a, U b)
{
	return a*b;
}
int main()
{
	cout << Mul(3.3, 2) << endl;
}