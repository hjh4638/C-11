#include <iostream>
using namespace std;

//���ٿ� Ÿ��
int main(){
	// ���ٴ� auto�� ������ �ֽ��ϴ�.
	auto f1 = [](int a, int b){return a + b; };
	auto f2 = [](int a, int b){return a + b; };
	
	//f1�� f2�� ���� Ÿ���ϱ��? �ٸ� Ÿ���ϱ��?

	//RTTI ����� �����Ϸ��� ������� �Լ���ü Ŭ������ �̸��� Ȯ�ΰ����մϴ�.
	cout << typeid(f1).name() << endl;
	cout << typeid(f2).name() << endl;

	cout << f1(1, 2) << endl;
}