#include <iostream>
using namespace std;

// ��������� ����� ���� ������
// 1. ��������� ���� �޸� �Ҵ��ؾ� �Ѵ�.
//	  static ��� data�� �ϸ� �ȵȴ�.!

// 2. COW(Copy On Write) : ���� �ڿ��� ���°� ����� ��
//							�ڿ��� �и��ؾ� �Ѵ�.

class Cat
{
	char* name;
	int	  age;

	int* ref; // ���� ����� ����ų ����
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);

		ref = new int(1); // �Ѱ��� 1�� �ʱ�ȭ
	}
	~Cat() { 
		// ���� ��� ����� �Ҹ���!
		if (--(*ref) == 0)
		{
			delete[] name;
			delete ref;
		}
	}

	// ���� ����� ������ ���� ������
	Cat(const Cat& c)
	{
		// 1. ��� ����� ���� ���� �Ŀ�
		name = c.name;
		age = c.age;
		ref = c.ref;

		// 2. ������� ����
		++(*ref);
	}
};
int main()
{
	Cat c1("NABI", 2);
	Cat c2(c1);

	c1.setName("AAA"); // c1 c2�� �ڿ��� ���� �и��Ǿ�� �Ѵ�.
						// Copy On Write(COW) ����!
	Cat c3("AA", 4);
	Cat c4(c3);
}