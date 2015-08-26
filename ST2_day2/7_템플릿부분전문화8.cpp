#include <iostream>
using namespace std;

////bool 기반 type selection 기술
//template<bool, typename T, typename U>
//struct IfThenElse
//{
//	typedef T ResultT;
//};
//template<typename T, typename U>
//struct IfThenElse<false, T, U>
//{
//	typedef U ResultT;
//};

//primary template을 보면 템플릿인자는 3개입니다.
//IfThenElse<bool 상수, 타입, 타입>


//C++11/14 기술
//람다와 유사한 trailing return 기술
template<typename T, typename U>
auto Mul(T a, U b) ->decltype(a*b)
{
	return a*b;
}
int main()
{
	cout << Mul(3.3, 2) << endl;
}