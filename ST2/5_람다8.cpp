#include <iostream>
#include <functional>
using namespace std;

int main(){
	//���ٴ� 3���� ���� ������ ���� �� �ֽ��ϴ�.
	auto f1 = [](int a, int b){return a + b; };

	int(*f2)(int, int) = [](int a, int b){return a + b; };

	function<int(int, int)> f3 = [](int a, int b){return a + b; };

	f1(1, 2); // �ζ��� ġȯ �ȴ�.
	f2(1, 2); // �ζ��� ġȯ �ȵȴ�.
	f3(1, 2); // �ζ��� ġȯ �ȵȴ�.

	//���ٿ� �Լ� ����
	foo([](int a, int b){return a + b; });
}

//���ٸ� ���ڷ� �޴� ��� - �Ʒ� 2���� ���������� �ζ��� ġȯ �ȵ�
void foo(int(*f2)(int, int)){}//ok
void foo(function<int(int,int)>f3){}//ok

//auto�� �Լ� ���ڰ� �� �� ����.!!
void foo(auto f1){} //foo(1)   => int
					//foo(3.4) => double

//�ζ��� ġȯ �����ϰ� ���ٸ� �޴� ������ ��� - template
template<typename T> void foo(T f){
	f(1, 2);
}