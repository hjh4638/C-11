#include <iostream>
using namespace std;

//C89 : �迭�� ũ��� ������ �ð� ����� �ȴ�.
//C99 : �迭�� ũ��� ������ �����ϴ�. gcc ����, VC++ ���� ����
int main(){
	int x1[3];

	int s2 = 3;
	//int x2[s2];// gcc ok.. vc:error

	const int s3 = 3;
	int x3[s3];// ok..

	const int s4[] = { 1, 2, 3 };
	int x4[s4[1]];//int x4[*(s4+1)] �ᱹ �迭 (s4)�� ������ �̹Ƿ�
}


void foo(const int s){
	int x[s];//�ɱ��? error
}