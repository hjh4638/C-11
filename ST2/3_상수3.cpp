#include <iostream>
using namespace std;


constexpr int foo( int a,  int b){
	return a + b;// �����Ϸ��� ������ �ð��� ��� ������ �� �� �����Ƿ�..
}
int main(){
	int n = 10;

	//C++98/03 ��Ÿ�� : 1998�� ǥ��ȭ �ǰ� 2003�� ������ C++
	const int c1 = 10;
	const int c2 = n;

	//C++11/14 : 2011�� 2�� ǥ��ȭ 2014�� ���׼���(������)
	constexpr int c3 = 10;
	//constexpr int c4 = n;
	
	//�迭 ũ��� �Լ��� ��밡��, �� �Լ����ϰ��� __�̾���Ѵ�.
	constexpr int a = 1;
	constexpr int b = 4;
	int x[foo(a,b)];
}