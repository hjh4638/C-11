
#include <iostream>
using namespace std;

class Cat
{
public:
	Cat(){ cout << "������" << endl; }
	~Cat(){ cout << "�Ҹ���" << endl; }
	
	// �Ҹ���, ���������, ������Կ����� -> Rule Of 3
	// + Move ������, Move ���Կ����� => Rule Of 5


	Cat(const Cat&){ cout << "���� ������" << endl; }
	Cat& operator=(const Cat&)
	{
		cout << "������Կ�����" << endl;
		return *this;
	}

	/*
	Cat(Cat&&){ cout << "Move ������" << endl; }

	Cat& operator=(Cat&&)
	{
		cout << "Move ���Կ�����" << endl;
		return *this;
	}
	*/
};

template<typename T> void Swap(T& a, T& b)
{
	T tmp = move(a);
	a = move(b);
	b = move(tmp);
}

int main()
{
	Cat c1;
	Cat c2;
	Swap(c1, c2);
}