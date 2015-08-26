// explicit 생성자를 가지는 클래스는 =로 초기화 할 수 없다.
// 반드시 () 초기화만 사용해야 한다.

#include <memory>
using namespace std;

int main()
{
	shared_ptr<int> p1(new int);
	shared_ptr<int> p2 = new int;

	// 안드로이드 프레임워크에서
	String16 s1 = "LedService.samsung.com"; // error.
	String16 s1("LedService.samsung.com"); // ok
}

void foo(String16 s){}

foo("hello"); // const char* => String16으로 암시적 변환되어야 한다.
			// String16은 explicit 생성자이므로 error

foo(String16("hello")); // ok..String16객체를 만들어서 전달

/*
class Test
{
	int data;
public:
	explicit Test(int n) : data(n){}
};

int main()
{
	// 아래 2줄의 차이점은?
	Test t1(5);			// 인자가 int 한개인 생성자 호출해서 객체 생성
	Test t2 = t1;		// 복사 생성자 호출
	Test t3 = 5;		// 1. 5를 변환생성자를 사용해서 Test 임시객체생성
						// 2. 복사 생성자를 호출해서 임시객체를 t3에 복사
}
*/