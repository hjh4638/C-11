#include <iostream>
using namespace std;
//
//int Mul(int a, int b)
//{
//	return a*b;
//}

template<typename T> T Mul(T a, T b)
{
	return a*b;
}
int main()
{
	cout << Mul(3.3, 2) << endl;
}