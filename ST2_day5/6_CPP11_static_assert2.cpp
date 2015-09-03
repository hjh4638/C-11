#include <iostream>
#include <type_traits>
using namespace std;
#pragma pack(1)
static_assert(sizeof(double) > 7, "double이 8보다 커야 컴파일됩니다.");

struct Packet
{
	char cmd;
	int data;

};

// Packet의 크기는 ?
// 구조체가 padding이 있다면 컴파일을 멈추게 해보자
static_assert( sizeof(Packet) == sizeof(char) + sizeof(int) , "unexpected padding");

class Test
{
	int data;
public:
	virtual void foo(){

	}
};

template<typename T> void foo(T a)
{
	static_assert(!is_polymorphic<T>::value, "T has virtual function");
	T tmp;
	memset(&tmp, 0, sizeof(T));
}
int main()
{
	Test t;
	foo(t);	
}