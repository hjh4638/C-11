#include <iostream>
using namespace std;

class Point{
public:
	int x, y;

	Point(int a = 0, int b = 0) :x(a), y(b){}
	void set(int a, int b){ x = a; y = b; }

	void printf() const
	{
		cout << x << ", " << y << endl;
		//x = 10; //��� �Լ� �ȿ����� ��� ���� ������ �� ����.
		cout << x << ", " << y << endl;
	}
};

int main(){
	const Point p(0, 0);
	p.x = 10;//error
	p.set(10, 10);//?error

	p.printf();//ȣ��ǰ� �Ϸ��� printf()�� ����Լ� �̾���Ѵ�.
	//"��� ��ü�� ��� �Լ��� ȣ�Ⱑ���ϴ�"
}