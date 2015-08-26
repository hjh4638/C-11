#include <iostream>
using namespace std;

//참조계수를 객체안에 포함시키자..
class Car
{
	// Car의 고유멤버들...
	int mCount; // 참조 계수
public:
	Car() :mCount(0){}
	~Car(){ cout << "~Car" << endl; }

	void incStrong(){ ++mCount; }
	void decStrong(){ if (--mCount == 0)delete this; }
};
int main()
{
	Car* p1 = new Car;
	p1->incStrong(); // 규칙 1. 객체 생성시 참조 계수 증가

	Car* p2 = p1;
	p2->incStrong(); // 규칙 2. 객체 파괴시 참조 계수 감소

	p2->decStrong();
	p1->decStrong(); // 규칙 3. 객체 사용 후 참조계수 감소
}