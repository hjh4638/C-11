#include <iostream>
using namespace std;

// CRTP를 사용해서 모든 자식 클래스의 부모가 다른 타입이 되게 하는
// 기술..
// 부모의 static 변수를 자식들이 각각 따로 사용하게 하는 기법.

template<typename T> class Count
{
public:
	static int cnt;
	static void print_count(){ cout << cnt << endl; }

	Count(){ ++cnt; }
	~Count(){ --cnt; }
};

template<typename T> int Count<T>::cnt = 0;
// -----------------------------
// Car 와 Truck 도 객체 갯수를 관리하고 싶다.
class Car : public Count<Car>
{};
class Truck : public Count<Truck>
{};
int main()
{
	Car c1, c2;
	Truck t1, t2;
	c1.print_count();
	
}