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

	void foo()
	{
		Cat c1("A", 2);
		//Cat c2 = c1; // 이것도 막고 싶다!
					 // 구현이 없으므로 link 에러!
	}
private:
	// private 복사 생성자 : 복사를 금지하고 싶을 때 사용하는 기술
//	Cat(const Cat& c){}
//	Cat& operator=(const Cat& c){}

	// C++11은 위 개념을 문법화 합니다.
	Cat(const Cat&) = delete; // 복사 생성자를 지워 달라
	Cat& operator=(const Cat&) = delete;
};
int main()
{
	Cat c1("NABI", 2);
	//c1.foo();
	Cat c2 = c1; // 복사를 금지하자..
				 // 컴파일시간 에러가 나오게 해보자.
}