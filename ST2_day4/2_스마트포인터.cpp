#include <iostream>
using namespace std;

class Car
{
public:
	void Go()	{ cout << "Car Go" << endl; }
	~Car()		{ cout << "~Car" << endl; }
};

// 개념 : 임의의 객체가 다른 타입의 포인터 처럼 사용되는 것

// 원리 : * 연산자와 -> 연산자를 재정의 해서 포인터 처럼 보이게한다.

//		주의 !! *연산자는 참조 리턴을 해야 합니다.

// 장점 : 진짜 포인터가 아니라 객체이다.
//		  생성/복사/대입/소멸의 모든 과정을 사용자가 제어할 수 있다.
//		  대표적 활용이 소멸자에서의 자동 삭제 기능
//		  (garbage collector와 유사한 기능)

// 아래 클래스가 핵심입니다.
class Ptr
{
	Car* obj;
public:
	Ptr(Car* p = 0) :obj(p){}

	~Ptr(){ delete obj; }
	Car* operator->(){ return obj; }
	
	// 주의 반드시 참조 리턴해야 합니다.
	// Car 리턴은 임시객체 입니다. - 다른 자동차가 만들어 집니다.!
	Car& operator*(){ return *obj; }
};

int main()
{
	//아래 2줄을 잘 생각해 보세요.
	Ptr p = new Car;		// Ptr p(new Car)로 생각해 보세요.
	p->Go();				// ( p.operator->()) Go() 의 모양이지만
							// ( p.operator->())->Go() 로 해석해 줍니다.

	(*p).Go(); // 진짜 포인터 처럼 보이려면 *도 되어야 한다.
}