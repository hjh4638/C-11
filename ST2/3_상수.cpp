#include <iostream>
using namespace std;

int main(){
	//const int c = 10; //������ �ð� ���, ��ũ�� ó�� �����Ѵ�.
	int n = 10;
	const int c = n; //��Ÿ�� ���, ����ð��� ���� �Ұ����ϴٴ� �ǹ�.
	//int* p = &c;//?? ����� �ּҸ� int*�� ���
				//error
	int* p = (int*)&c;//ok.. �Ǵ� C++ const_cast<>�� ok
	*p = 20;
	cout << c << endl;
	cout << *p << endl;
}