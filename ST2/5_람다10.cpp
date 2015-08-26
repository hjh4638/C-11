#include <iostream>
using namespace std;

int main(){
	int v1 = 10;
	int v2 = 20;

	//�������� ĸ��
	//auto f = [v1](int a, int b){return a + b + v1; };
	//auto f = [=](int a, int b){return a + b + v1; };

	//������ ���� ĸ��
	//auto f = [&v1](int a, int b){v1 = 0; return a + b; };
	auto f = [&](int a, int b){v1 = 0; return a + b; };
	cout << f(1, 2) << endl;
	cout << v1 << endl;
}