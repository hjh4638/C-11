#include <iostream>
using namespace std;

//template meta programming : ������ �ÿ� ������ �����ϴ� ��

//������ �ð� ��͸� Ȱ���Ѵ�.
//����� ������ ���ؼ� ����ȭ ������ Ȱ��ȴ�.
//��Ÿ �Լ���� �θ���!!!!

//template ���ڷ� Ÿ���� �ƴ� ������ ������ �˴ϴ�.
template<int N> struct Factorial
{
	enum{value = N* Factorial<N-1>::value};
};
template<> struct Factorial < 1 >
{
	enum{value=1};
};
int main()
{
	int n = Factorial<5>::value; //�� ������ ������!!!
			//5*F<4>::v
			//5*F<4>::v
	cout << n << endl;

	int a = 5; cin >> a;
	int n2 = Factorial<a>::value; //error. ���ø� ���ڴ�
									//������ �ð� ����� ����!!

	//���� 1. binary<> ��������
	int n3 = binary<101>::value;
	
	cout << n3 << endl;


	//���� 2. �Ʒ� �ڵ尡 ������ ���� ������ �غ�����
	int n4 = binary<201>::value;
	
}

//���� ������ �Բ�
//smkang@ioacademy.co.kr�� �����ּ���..
//������ ������.. ���Ͻź��� ���� �ּ���..