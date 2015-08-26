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

	// C++98 : 생성자, 복사 생성자
	// C++11 : 생성자, 복사 생성자, Move 생성자
	Cat(const Cat& c) // 복사 생성자 - 예전 방식과 모양 동일
	{
		// 깊은 복사나 참조계수기법으로 구현
		cout << "복사 생성자" << endl;
	}

	// Move 생성자 - rvalue reference를 사용하기로 결정했다
	Cat(Cat&& c)
	{
		cout << "Move 생성자 호출" << endl;
		
		// 소유권 이전으로 구현
		// 1. 얕은 복사후에
		name = c.name;
		age = c.age;

		// 2. 원본을 0으로
		c.name = 0;
		c.age = 0;
	}
};

//template<typename T> void Swap(T& a, T& b)
//{
//	// 일반적인 swap 알고리즘
//	T tmp = a; // 복사 생성자 호출
////	a = b;	   // 대입 연산자 호출
////	b = tmp;   // 대입 연산자 호출
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