#include <iostream>
using namespace std;

// ������ ����� ���� Ŭ������ �ִٸ� �ݵ�� ���� �����ڸ� ������
// ������ �Ѵ�.
// �׷��� �ʴٸ� �����Ϸ��� ����� ����Ʈ �����ڴ� �������� ������ 
// �ִ�..

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

	// �ڱ� �ڽ��� Ÿ�� �ϳ��� ���ڷ� ������ �����ڸ�
	// �����Ϸ��� ����� �ݴϴ�. - ���� ���� �����ڶ�� �մϴ�.
	Cat(const Cat& c)
	{
		name = c.name;
		age = c.age;
	}
};
int main()
{
	Cat c1("NABI", 2);
//	Cat c2 = c1; // runtime error!!! ���� ���� (Shallow Copy)

	Cat c2(c1); // �� ������ �� ǥ���� �����մϴ�.
}