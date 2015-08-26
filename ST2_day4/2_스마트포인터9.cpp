#include <iostream>
#include <vector>
#include <list>
using namespace std;

// 객체 관리의 어려움
class Car{};

vector<Car*>	v;
list<Car*>		s;

void foo()
{
	Car* p = new Car;
	v.push_back(p);
	s.push_back(p);

	// 여기서는 더이상 p가 필요없다. 제거해도 될까?
	delete p;
}

int main()
{
	foo();
}