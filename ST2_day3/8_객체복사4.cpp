#include <iostream>
using namespace std;

class Cat
{
	char* name;
	int	  age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}
	~Cat() { delete[] name; }

	// ������������ ���� ������ - ��ư� �߿��� �����Դϴ�.
	// Move �����ڶ�� �θ��� ����
	Cat(Cat& c) // ���� !! const�� �����ϴ�.
	{
		// 1. ���� �����Ŀ�
		name = c.name;
		age = c.age;

		// 2. ������ 0����
		c.name = 0;
		c.age = 0;
	}
};
int main()
{
	Cat c1("NABI", 2);
	Cat c2(c1);
}