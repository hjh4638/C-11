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

	// C++98 : ������, ���� ������
	// C++11 : ������, ���� ������, Move ������
	Cat(const Cat& c) // ���� ������ - ���� ��İ� ��� ����
	{
		// ���� ���糪 �������������� ����
		cout << "���� ������" << endl;
	}

	// Move ������ - rvalue reference�� ����ϱ�� �����ߴ�
	Cat(Cat&& c)
	{
		cout << "Move ������ ȣ��" << endl;
		
		// ������ �������� ����
		// 1. ���� �����Ŀ�
		name = c.name;
		age = c.age;

		// 2. ������ 0����
		c.name = 0;
		c.age = 0;
	}
};

//template<typename T> void Swap(T& a, T& b)
//{
//	// �Ϲ����� swap �˰���
//	T tmp = a; // ���� ������ ȣ��
////	a = b;	   // ���� ������ ȣ��
////	b = tmp;   // ���� ������ ȣ��
//}

/*
template<typename T> T&& move(T& a)
{
	return static_cast<T&&>(a);
}
*/
template<typename T> void Swap(T& a, T& b)
{
	T tmp = move(a);

}
int main()
{
	Cat c1("NABI", 2);
	Cat c2("AA", 2);
	Swap(c1, c2);
}