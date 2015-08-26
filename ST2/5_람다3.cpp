#include <iostream>
using namespace std;

//함수객체
struct Plus{
	int operator()(int a, int b){
		return a + b;
	}
};

int main(){
	Plus p;
	int n = p(1, 2);//이 한줄을 잘 생각해 보세요.
					//p.operator()(1,2)로 해석 됩니다.
					//결국 () 연산자만 재정의하면 함수처럼 사용가능합니다.
			
	cout << n << endl;
}