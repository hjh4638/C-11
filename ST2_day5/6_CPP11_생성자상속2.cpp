// C++11�� using�� �����ڷ� ��밡���ϰ� �߽��ϴ�.

class Base
{
	int data;
public:
	Base() :data(0){}
	Base(int a) :data(a){}
};
class Derived : public Base
{
public:
	using Base::Base; // �θ� �����ڵ� ����� �޶� - C++11
	Derived(){ }
};
int main()
{
	Derived d1;
	Derived d2(1); // ?
}