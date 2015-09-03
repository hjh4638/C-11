#include <iostream>
#include <type_traits>
using namespace std;
#pragma pack(1)
static_assert(sizeof(double) > 7, "double�� 8���� Ŀ�� �����ϵ˴ϴ�.");

struct Packet
{
	char cmd;
	int data;

};

// Packet�� ũ��� ?
// ����ü�� padding�� �ִٸ� �������� ���߰� �غ���
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