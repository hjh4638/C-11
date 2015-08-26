#include <iostream>
using namespace std;

// CRTP�� ����ؼ� ��� �ڽ� Ŭ������ �θ� �ٸ� Ÿ���� �ǰ� �ϴ�
// ���..
// �θ��� static ������ �ڽĵ��� ���� ���� ����ϰ� �ϴ� ���.

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
// Car �� Truck �� ��ü ������ �����ϰ� �ʹ�.
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