#include <iostream>
using namespace std;
//�ٽ�:��� �Լ��� �ʼ��̴�.
//��ü�� ���¸� �������� ���� ��� ��� �Լ��� �ݵ�� ����Լ��� �������Ѵ�.

//void foo(const Rect& r) �ڵ忡�� r�� ���Ͽ� ������ ���� �� �־�� �Ѵ�!!
class Rect{
	int x, y, w, h;
public:
	int getArea()const{ return w*h; }
};

//C++ �⺻ ��� : call by value ��� const &�� ����.!!
void foo(const Rect& r){
	int n = r.getArea();
}
int main(){
	Rect r;//�ʱ�ȭ �ߴٰ� �����ϰ�
	int n = r.getArea();//ok..
	foo(r);
}