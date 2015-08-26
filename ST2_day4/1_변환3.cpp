// explicit �����ڸ� ������ Ŭ������ =�� �ʱ�ȭ �� �� ����.
// �ݵ�� () �ʱ�ȭ�� ����ؾ� �Ѵ�.

#include <memory>
using namespace std;

int main()
{
	shared_ptr<int> p1(new int);
	shared_ptr<int> p2 = new int;

	// �ȵ���̵� �����ӿ�ũ����
	String16 s1 = "LedService.samsung.com"; // error.
	String16 s1("LedService.samsung.com"); // ok
}

void foo(String16 s){}

foo("hello"); // const char* => String16���� �Ͻ��� ��ȯ�Ǿ�� �Ѵ�.
			// String16�� explicit �������̹Ƿ� error

foo(String16("hello")); // ok..String16��ü�� ���� ����

/*
class Test
{
	int data;
public:
	explicit Test(int n) : data(n){}
};

int main()
{
	// �Ʒ� 2���� ��������?
	Test t1(5);			// ���ڰ� int �Ѱ��� ������ ȣ���ؼ� ��ü ����
	Test t2 = t1;		// ���� ������ ȣ��
	Test t3 = 5;		// 1. 5�� ��ȯ�����ڸ� ����ؼ� Test �ӽð�ü����
						// 2. ���� �����ڸ� ȣ���ؼ� �ӽð�ü�� t3�� ����
}
*/