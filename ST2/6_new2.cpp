#include <iostream>
using namespace std;

//operator new �� ������ (overloading)�� �� �ֽ��ϴ�.

void* operator new(size_t sz){
	cout << "my new" << endl;
	return malloc(sz);
}
//�Լ� �����ε��� �����մϴ�. ��, 1��° ���ڴ� �ݵ�� size_t�̾�� 
//�մϴ�.
void* operator new(size_t sz, char* s, int n){
	cout << "my new" << endl;
	return malloc(sz);
}
void operator delete(void* p){
	cout << "my delete" << endl;
	free(p);
}

int main(){
	int* p1 = new("AAA", 3) int; // sizeof(int) �� 4�� ���ڷ� ����
	delete p1;
}