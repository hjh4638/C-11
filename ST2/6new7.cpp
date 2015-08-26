#include <iostream>
using namespace std;
//단지, 사용되지 않고 함수 오버로딩을 위한 인자가 필요 할때는
//새로운 타입을 설계하는 것이 좋다 - "empty class" 개념

struct nothrow__t {};//empty class - 아무 멤버도 없다.
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