#include <iostream>
#include <vector>
#include <list>
using namespace std;

// ��ü ������ �����
class Car{};

vector<Car*>	v;
list<Car*>		s;

void foo()
{
	Car* p = new Car;
	v.push_back(p);
	s.push_back(p);

	// ���⼭�� ���̻� p�� �ʿ����. �����ص� �ɱ�?
	delete p;
}

int main()
{
	foo();
}