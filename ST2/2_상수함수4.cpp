#include <iostream>
using namespace std;

//���� ����� : �ܺο��� �ٶ󺼶��� ��� �Լ��� �Ǿ������� ���������δ� ��� ������ ���� �����ؾ� �ϴ� ����
// 1. ���ϴ� ����� mutable�� !!
class Point{
	int x, y;
	mutable char cache[32];
	mutable bool cache_valid;
public:
	Point(int a = 0, int b = 0) :x(a), y(b), cache_valid{false){}

	//��ü�� ���¸� ���ڿ��� ��ȯ�ϴ� �Լ� : java, C#�� �ִ� ����
	char* toString() const
	{
		static char s[32];
		sprintf_s(s, "%d %d", x, y);
		return s;
	}
};
int main(){
	Point p(1, 2);
	cout << p.toString() << endl;
	cout << p.toString() << endl;
}