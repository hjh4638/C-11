#include <iostream>
#include <time.h>
using namespace std;

class Timer
{
	int count;
public:
	Timer()
	{
		count = clock();
	}
	~Timer()
	{
		int n = clock();
		cout << "걸린 시간 : " << n - count << endl;
	}

};

void foo()
{
	cout << "foo" << endl;
	for (int i = 0; i < 1000000; i++);
}

template<typename F, typename ... Types>
void HowLong(F f, Types&& ... args)
{
	Timer u;
	return f(forward<Types&&>(args)...);
}

int main()
{
	HowLong(foo);
}