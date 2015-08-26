#include <iostream>
using namespace std;

////bool ��� type selection ���
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

//primary template�� ���� ���ø����ڴ� 3���Դϴ�.
//IfThenElse<bool ���, Ÿ��, Ÿ��>


//C++11/14 ���
//���ٿ� ������ trailing return ���
template<typename T, typename U>
auto Mul(T a, U b) ->decltype(a*b)
{
	return a*b;
}
int main()
{
	cout << Mul(3.3, 2) << endl;
}