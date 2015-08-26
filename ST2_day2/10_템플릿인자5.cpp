#include <iostream>
using namespace std;

// 가변인자 템플릿. - C++11 기술
template<typename ... Types>
void foo(Types ... args)
{

}

template<typename ... Types> class Test
{

};
int main()
{
	foo(1);
	foo(1, 3.3); // Types => int, double
				 // args  => 1, 3.3
	Test<int, double> t2;
	Test<int> t1;
}