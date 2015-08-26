
#include <iostream>
using namespace std;

class Cat
{
public:
	Cat(){ cout << "생성자" << endl; }
	~Cat(){ cout << "소멸자" << endl; }
	
	// 소멸자, 복사생성자, 복사대입연산자 -> Rule Of 3
	// + Move 생성자, Move 대입연산자 => Rule Of 5


	Cat(const Cat&){ cout << "복사 생성자" << endl; }
	Cat& operator=(const Cat&)
	{
		cout << "복사대입연산자" << endl;
		return *this;
	}

	/*
	Cat(Cat&&){ cout << "Move 생성자" << endl; }

	Cat& operator=(Cat&&)
	{
		cout << "Move 대입연산자" << endl;
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