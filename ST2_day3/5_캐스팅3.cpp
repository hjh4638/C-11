#include <iostream>
using namespace std;

class X{ public: int x; };
class Y{ public: int y; };

class C : public X, public Y{};

int main()
{
	C c;
	cout << &c << endl; //100���� ��� �Ҷ�

	//Y* py = &c; // 104����
	//Y* py = (Y*) &c;
	
	//Y* py = static_cast<Y*>(&c); // 104
									// &c �޸𸮿��� Y�� ã�ƶ�
									// ���ٸ� error
									// ����ð��� �ƴ� 
									// ������ �ð���!!!
	Y* py = reinterpret_cast<Y*>(&c); // &c �ּҸ� ������ Y*��
									// �����ϰڴٴ°�!!
									// C�� Y�� ��������
									// ���� ������� ����

	py->y = 10; // c�� ���忡���� ��� ���ϱ��?
	
	cout << c.x << endl; // 10

	cout << py << endl; // ??
}