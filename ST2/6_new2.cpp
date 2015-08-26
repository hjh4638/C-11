#include <iostream>
using namespace std;

//operator new 는 재정의 (overloading)할 수 있습니다.

void* operator new(size_t sz){
	cout << "my new" << endl;
	return malloc(sz);
}
//함수 오버로딩이 가능합니다. 단, 1번째 인자는 반드시 size_t이어야 
//합니다.
void* operator new(size_t sz, char* s, int n){
	cout << "my new" << endl;
	return malloc(sz);
}
void operator delete(void* p){
	cout << "my delete" << endl;
	free(p);
}

int main(){
	int* p1 = new("AAA", 3) int; // sizeof(int) 즉 4가 인자로 전달
	delete p1;
}