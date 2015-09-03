#include <iostream>
#include <string>
#include <complex>
using namespace std;

void foo(char const* s)	{ cout << "char*" << endl; }
void foo(string s)		{ cout << "string" << endl; }

int main()
{
	foo("hello"); // 1
	foo(string("hello")); // 2

	foo("hello"s);//2

	complex<int> c1(3); // 3+0i
	cout << c1 << endl;

	complex<int> c2(0, 3); // 0 + 3i
	cout << c2 << endl;

	complex<int> c3(3i); // 0 + 3i
	cout << c3 << endl;
}