#include <iostream>
using namespace std;

// 포인터 멤버를 가진 클래스가 있다면 반드시 복사 생성자를 재정의
// 만들어야 한다.
// 그렇지 않다면 컴파일러가 만드는 디폴트 생성자는 얕은복사 현상이 
// 있다..

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

	// 자기 자신의 타입 하나를 인자로 가지는 생성자를
	// 컴파일러가 만들어 줍니다. - 흔히 복사 생성자라고 합니다.
	Cat(const Cat& c)
	{
		// 깊은 복사(Deep Copy)를 사용한 복사 생성자
		// 1. 포인터가 아닌 멤버는 그냥 복사
		age = c.age;

		// 2. 포인터 멤버는 메모리 할당후
		name = new char[strlen(c.name) + 1];

		// 3. 메모리를 통째로 복사
		strcpy(name, c.name);
	}
};
int main()
{
	Cat c1("NABI", 2);
	//	Cat c2 = c1; // runtime error!!! 얕은 복사 (Shallow Copy)

	Cat c2(c1); // 위 한줄은 이 표현과 유사합니다.
}