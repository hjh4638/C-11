#include <iostream>
using namespace std;

int x = 10;

int& foo() { return x; }

int main()
{
	auto n = foo(); // ��Ģ 1. �캯�� Ÿ����
					// const, reference, volatile�� ������
					// n�� Ÿ���� ???? template�� ����
					// auto : T		n : param		expr : = foo()

	auto& r = foo(); // ��Ģ 2. �캯�� �Ӽ��� ���۷�������
					 // auto : T	r : int&		
	n = 20;
	r = 20;

	cout << n << endl;
}