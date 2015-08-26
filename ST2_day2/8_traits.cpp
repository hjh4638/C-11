#include <iostream>
using namespace std;

template<typename T> void printv(T a)
{
	cout << a << endl;
}
template<typename T> void printv(T a)
{
	if (T is Pointer)
		cout << a << ", " << *a << endl;
	else
		cout << a << endl;
}
int main()
{
	int n = 3;
	double d = 3.3;

	printv(n);
	printv(d);

	printv(&d);
}