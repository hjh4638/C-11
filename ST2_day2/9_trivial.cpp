#include <iostream>
#include <type_traits>
using namespace std;

//trivial constructor(자명한 생성자) : 아무 일도 하지 않는 생성자

//1. 가상함수가 없고
//2. 부모가 없거나 부모의 생성자가 trivial 하고
//3. 객체형 멤버가 없거나 객체형 멤버의 생성자가 trivial 하고
//4. 사용자가 만든 생성자가 없다면

//생성자는 "trivial" 하다!!

class Base{};

class A //: public Base
{
	//Base b;
public:
	//virtual void foo(){}
};

int main()
{
	//A의 생성자는 trivial 할까요 ??
	A* p = (A*)malloc(sizeof(A));//생성자가 호출되지 않는다.

	new(p) A;//p 메모리에 대해 생성자 호출
			 // "placement new"s
	p->foo();
}