#include <iostream>
using namespace std;

// ���� ������ (delegating constructor)
class Point
{
public:
	int x = 0; // class �ȿ��� ��� ������ ��������� �ٷ� �ʱ�ȭ ����
	int y = 0; // java C# ó��
	int a{ 0 }; // ���� �����ϴ� ��Ÿ��

	Point(int a, int b) :x(a), y(b){}
	Point() : Point(0,0) // �����ڿ��� �ٸ� �����ڸ� ȣ���ϴ� �ڵ�
	{
		//this(0,0)
		//Point(0, 0); // �����ڿ��� �ٸ� ������ ȣ���� �ƴϰ�
					 // �ӽð�ü�� ����� ǥ���̴�.
	}
};
int main()
{
	Point p;
	cout << p.x << endl;
}