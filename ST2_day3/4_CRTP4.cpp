#include <iostream>
using namespace std;

class Count
{
public:
	static int cnt;
	static void print_count(){ cout << cnt << endl; }

	Count(){ ++cnt; }
	~Count(){ --cnt; }
};

int Count::cnt = 0;

int main()
{
	Count c1, c2;
	c1.print_count();
}