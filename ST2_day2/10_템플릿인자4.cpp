#include <iostream>
#include <list>
#include <vector>
using namespace std;

template<typename T, template<typename, typename> class C> class Stack
{
	C<T, allocator<T>> c;
public:
	void push(const T& a){ c.push_back(a); }
};

int main()
{
	Stack<int, list> s;
	s.push(10);
}