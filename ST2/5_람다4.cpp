// 5_����4
// �� �Լ� ��ü�� ����ϴ°�? - ���� �߿��մϴ�.

//1. �Ϲ��Լ��� �ڽŸ��� Ÿ���� ���� - �ݵ�� �����ؾ��մϴ�.
//	  signature�� ������ �Լ��� ���� Ÿ���̴�.

//2. �Լ� ��ü�� �ڽŸ��� Ÿ���� �ִ�.
//	 signature�� �����ص� ��� �Լ���ü�� �ٸ� Ÿ���̴�.
#include <iostream>
using namespace std;
struct lesss{
	inline bool operator()(int a, int b){ return a < b; }
};
struct greater{
	inline bool operator()(int a, int b){ return a > b; }
};
//�Ʒ� �Լ��� cmp()�� �ζ��� ġȯ������ greater�� ��ü�� �� ����.
//void Sort(int* x, int n, lesss cmp){

//��å��ü�� �����ϰ� ��å�� �ζ��� ġȯ�Ǵ� �Լ�
//"���ø� + �Լ���ü"�� ����� ���
template<typename T>
void Sort(int* x, int n, T cmp){
	for (int i = 0; i < n - 1; i++){
		for (int j = 1 + 1; j < n; j++){
			//if (x[i]>x[j]){
			if (cmp(x[i], x[j])){//�ζ��� ġȯ ����.
				swap(x[i], x[j]);
			}
		}
	}
}
lesss f1; Sort(x, 10, f1);
greater f2; Sort(x, 10, f2);