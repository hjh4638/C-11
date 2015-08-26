#include <iostream>
using namespace std;

//아래 코드에서 잘못된 점을 찾아 보세요.
/*
//1998 표준화 이전에 만든 코드가 있다면 아래 한줄만 추가한다.
#define new new(nothrow)

int main(){
	int* p = new int[100];

	if (p == 0){
		cout << "메모리 부족" << endl;
	}
	else{
		delete[] p;
	}
}
*/
//new 실패시 예외가 발생합니다.
int main(){
	int* p2 = new(nothrow) int[100];
	int* p = 0;

	try{
		p = new int[100];
		//...
		delete[] p;
	}
	catch (std::bad_alloc& e){
		cout << "메모리 부족" << endl;
	}
}