#include <iostream>
using namespace std;

// dynamic_cast�� �����Լ� ���̺� �ִ� type ������ ����մϴ�.
// �׷��� �����Լ��� �ݵ�� 1�� �̻� �־�� �մϴ�.

// C++ �⺻ : ��� �θ��� �Ҹ��ڴ� �����Լ� �̾�� �Ѵ�.
//			��� ��Ģ�� �����Ƿ� ��κ� �Ѱ� �̻��� �����Լ��� �ֽ��ϴ�.
class Animal{
public:
	virtual ~Animal(){}
};

class Dog : public Animal
{
public:
	int color;
};
//-----------------------------
// ��� ������ ������ ��ɸ� �����Ѵٸ� �θ��� Animal*�� ���ڷ�!!
void foo(Animal* p)
{
	// ��� ������ ���� ��� ������

	// Dog��� ���� ����
	//p->color = 10; // p�� Animal* �̹Ƿ� color�� ����

	// �ٿ�(Down) ĳ��Ʈ : �θ� ������ => �ڽ������ͷ� �����ϴ°�
	// static_cast : �ٿ� ĳ��Ʈ �� �� ���� Dog������ Ȯ�� �� ������.
	//				 ������ �ð����� �޸𸮸� ������ �� �����Ƿ�!!
	// Dog* pDog = static_cast<Dog*>(p);

	// ����ð��� p�� ����Ű�� �޸𸮸� �����ؼ� Dog�� �´� ��츸
	// ����. �ƴϸ� 0 ����
	Dog* pDog = dynamic_cast<Dog*>(p);
	cout << pDog << endl;
	
	if (pDog !=0)
		pDog->color = 10;
}

void goo(Animal* p){} // �����۾���

// Dog�� ���� �۾��� �߰��Ϸ��� ���� goo�� �������� ����
// �Ʒ�ó�� ����� ���� ���� ������
void goo(Dog* p)
{
	goo(static_cast<Animal*>(p));

	// Dog ���� �۾�
}
int main()
{
	//Dog d;	foo(&d);
	Animal a; foo(&a);
}