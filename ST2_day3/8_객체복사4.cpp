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

	// 소유권이전의 복사 생성자 - 어렵고 중요한 개념입니다.
	// Move 생성자라고 부르는 개념
	Cat(Cat& c) // 주의 !! const가 없습니다.
	{
		// 1. 얕은 복사후에
		name = c.name;
		age = c.age;

		// 2. 원본을 0으로
		c.name = 0;
		c.age = 0;
	}
};
int main()
{
	Cat c1("NABI", 2);
	Cat c2(c1);
}