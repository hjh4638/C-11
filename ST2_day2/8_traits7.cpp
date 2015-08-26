#include <iostream>
using namespace std;

#include <type_traits> //�̾ȿ� integral_constant<>��
					   //is_pointer<> ���� 100���� traits�� �ֽ��ϴ�.

void check(true_type){ cout << "check : ������" << endl; }
void check(false_type){ cout << "check : ������ �ƴ�" << endl; }
template<typename T> void foo(const T& a)
{
	//traits ����� 1. value ������ ����
	//���� : �����Ͱ� �ƴ� else�� �ȿ��� *a ���� ǥ���� ������ �ȵȴ�.
	if (is_pointer<T>::value){
		cout << "������" << endl;
	}
	else
		cout << "������ �ƴ�" << endl;

	//2. �Լ� �����ε�
	//���� : �����Ϳ� ������ �ƴ� ��찡 ������ �Լ��� ó����
	//		*a���� ǥ�� ����
	check(is_pointer<T>());
}

int main()
{
	int n = 10;
	foo(&n);
	foo(n);
}