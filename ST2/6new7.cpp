#include <iostream>
using namespace std;
//����, ������ �ʰ� �Լ� �����ε��� ���� ���ڰ� �ʿ� �Ҷ���
//���ο� Ÿ���� �����ϴ� ���� ���� - "empty class" ����

struct nothrow__t {};//empty class - �ƹ� ����� ����.
nothrow__t nothrow_;//sizeof(nothrow) = > 1byte

void* operator new(size_t sz){
	void* p = malloc(sz);
	if (p == 0){
		throw std::bad_alloc();
	}
	return p;
}
void* operator new(size_t sz, nothrow__t n){
	void* p = malloc(sz);
	return p;
}
//#define nothrow 1
int main(){
	int* p = new(nothrow_) int[100];
	return 0;
}