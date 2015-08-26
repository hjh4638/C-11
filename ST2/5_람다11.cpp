#include <iostream>
using namespace std;

int main(){
	int v1 = 10;
	int v2 = 20;
	
	auto f = [v1](int a, int b){return a + b + v1; };
	
	//위 한줄의 정확한 원리
	class closure_object{
		int value1;
	public:
		closure_object(int v1) :value1(v1){}

		inline int operator()(int a, int b)const{
			return a + b;
		}
	};
	//auto f = closure_object(v1);
}