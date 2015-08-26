#include <iostream>
using namespace std;

// C++�� 4���� ĳ���� �����ڸ� �����Ѵ�.

// static_cast : void* => �ٸ� Ÿ���� ���
//					�� �ܿ��� �������� �־�� �Ѵ�.!!
// reinterpre_cast : �޸��� ���ؼ�, ��κ� ����.
// const_cast :
// dynamic_cast : 

int main()
{
	int* p3 = static_cast<int*>(malloc(100));  // void* => int* ��ȯ
											   // 
	int n = 10;
	//double* p = (double*) &n; //����� ��ȯ - ok
	//double* p = static_cast<double*>(&n); // int* => double*
										// error
	double* p = reinterpret_cast<double*>(&n); //ok..

	const int c = 10;
	//int* p2 = (int*)&c;
	//int* p2 = static_cast<int*>(&c); // error
	//int* p2 = reinterpret_cast<int*>(&c); // error. 
										// ����� ���Ŵ� �ȵ�.

	int* p2 = const_cast<int*>(&c); // ok.. ����� ����
	// ������ �Ʒ�ó�� ����ϸ� ���� ȥ�������� ���ϴ�..
	*p2 = 20;

	cout << c << endl;
	cout << *p2 << endl;
}