#include <iostream>
using namespace std;

int main(){
	//auto f1 = [](){cout << "f1" << endl; };

	//���ڰ� ���� ���ٴ� ()�� ������ �����ϴ�.
	//Nullary Lamda expression
	auto f1 = []{cout << "f1" << endl; };

	f1();
}