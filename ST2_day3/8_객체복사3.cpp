#include <iostream>
using namespace std;

// 참조계수를 사용한 복사 생성자
// 1. 참조계수는 동적 메모리 할당해야 한다.
//	  static 멤버 data로 하면 안된다.!

// 2. COW(Copy On Write) : 공유 자원의 상태가 변경될 때
//							자원을 분리해야 한다.

class Cat
{
	char* name;
	int	  age;

	int* ref; // 참조 계수를 가르킬 변수
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);

		ref = new int(1); // 한개를 1로 초기화
	}
	~Cat() { 
		// 참조 계수 방식의 소멸자!
		if (--(*ref) == 0)
		{
			delete[] name;
			delete ref;
		}
	}

	// 참조 계수로 구현한 복사 생성자
	Cat(const Cat& c)
	{
		// 1. 모든 멤버를 얕은 복사 후에
		name = c.name;
		age = c.age;
		ref = c.ref;

		// 2. 참조계수 증가
		++(*ref);
	}
};
int main()
{
	Cat c1("NABI", 2);
	Cat c2(c1);

	c1.setName("AAA"); // c1 c2의 자원은 이제 분리되어야 한다.
						// Copy On Write(COW) 개념!
	Cat c3("AA", 4);
	Cat c4(c3);
}